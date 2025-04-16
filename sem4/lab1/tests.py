import unittest

from functions import *

class TestPrinter(unittest.TestCase):

    def setUp(self):
        paper: List[Paper] = 15 * [Paper('А4')]
        self.printer: Printer = Printer(Cartridge(Ink('водяные', 3), 3),
                                        paper, 'HP LaserJet', 'цветной')
        self.driver: Driver = Driver(self.printer)
        self.maintenance: Maintenance = Maintenance()

    def test_print_text_document(self):
        pages: List[Page] = [Page('p1'), Page('p2'), Page('p3'), Page('p4'), Page('p5')]
        document: PrintDocument = PrintDocument('текст', 'doc1.docx', pages)
        print_pages: List[Page] = [pages[i] for i in range(len(pages)) if i % 2 == 0]
        print_parameters: Dict[str, Union[str, int, List[Page]]] = {'pages': print_pages,
                                               'side_print': 'двусторонняя',
                                               'format': 'А4',
                                               'orientation': 'альбомная',
                                               'copy': 2
                                               }
        result: List[Page] = self.printer.print_document(document, print_parameters)

        self.assertEqual(result, 2 * print_pages)
        self.assertEqual(self.printer.find_number_of_paper_in_format('А4'), 11)
        self.assertEqual(self.printer.cartridge.ink.volume, 2.82)

    def test_print_image(self):
        image: PrintDocument = PrintDocument('изображение', 'image1.png',
                                             [Page('изображение "image1.png"')])
        print_parameters: Dict[str, Union[str, int, List[Page]]] = {'format': 'А4',
                                               'orientation': 'альбомная',
                                               'copy': 3
                                               }
        result: List[Page] = self.printer.print_document(image, print_parameters)

        self.assertEqual(result, 3 * [Page('изображение "image1.png"')])
        self.assertEqual(self.printer.find_number_of_paper_in_format('А4'), 12)
        self.assertEqual(self.printer.cartridge.ink.volume, 2.76)

    def test_unsuccessful_print(self):
        image: PrintDocument = PrintDocument('изображение', 'image1.png',
                                             [Page('изображение "image1.png"')])
        print_parameters: Dict[str, Union[str, int, List[Page]]] = {'format': 'А4',
                                               'orientation': 'альбомная',
                                               'copy': 3
                                               }
        self.printer.paper = 2 * [Paper('А4')]
        result: List[Page] = self.printer.print_document(image, print_parameters)

        self.assertEqual(result, [])
        self.assertEqual(self.printer.find_number_of_paper_in_format('А4'), 2)
        self.assertEqual(self.printer.cartridge.ink.volume, 3)

        self.printer.paper = 5 * [Paper('А4')]
        self.printer.cartridge.ink.volume = 0.2
        result: List[Page] = self.printer.print_document(image, print_parameters)

        self.assertEqual(result, [])
        self.assertEqual(self.printer.find_number_of_paper_in_format('А4'), 5)
        self.assertEqual(self.printer.cartridge.ink.volume, 0.2)

        self.printer.cartridge.ink_filling = 6
        self.printer.cartridge.ink.volume = 3
        result: List[Page] = self.printer.print_document(image, print_parameters)

        self.assertEqual(result, [])
        self.assertEqual(self.printer.find_number_of_paper_in_format('А4'), 5)
        self.assertEqual(self.printer.cartridge.ink.volume, 3)

    def test_driver_control(self):
        pages: List[Page] = [Page('p1'), Page('p2'), Page('p3'), Page('p4'), Page('p5')]
        document: PrintDocument = PrintDocument('текст', 'doc1.docx', pages)
        print_pages: List[Page] = [pages[i] for i in range(len(pages)) if i % 2 == 0]
        print_parameters: Dict[str, Union[str, int, List[Page]]] = {'pages': print_pages,
                                               'side_print': 'односторонняя',
                                               'format': 'А4',
                                               'orientation': 'альбомная',
                                               'copy': 5
                                               }
        new_parameters: Dict[str, Union[str, int, List[Page]]] = {'pages': print_pages,
                                             'side_print': 'односторонняя',
                                             'format': 'А4',
                                             'orientation': 'альбомная',
                                             'copy': 1
                                             }
        self.driver.add_document(document, print_parameters)
        self.assertEqual(self.driver.queue, 5 * [{'document': document, 'parameters': new_parameters}])

        self.driver.delete_document(1)
        self.assertEqual(self.driver.queue, 4 * [{'document': document, 'parameters': new_parameters}])

        result: List[Page] = self.driver.print_document(1)
        self.assertEqual(self.driver.queue, 3 * [{'document': document, 'parameters': new_parameters}])
        self.assertEqual(result, print_pages)
        self.assertEqual(self.printer.find_number_of_paper_in_format('А4'), 12)
        self.assertEqual(self.printer.cartridge.ink.volume, 2.91)

    def test_clean(self):
        self.printer.maintenance_is_need = True
        self.printer.needed_maintenance = 'Требуется очистка принтера'
        self.maintenance.clean_is_need = True
        self.maintenance.clean(self.printer)

        self.assertEqual(self.printer.maintenance_is_need, False)
        self.assertEqual(self.printer.needed_maintenance, '')
        self.assertEqual(self.maintenance.clean_is_need, False)

    def test_program_maintenance(self):
        self.printer.maintenance_is_need = True
        self.printer.needed_maintenance = 'Требуется программное обслуживание принтера'
        self.maintenance.program_maintenance_is_need = True
        self.maintenance.program_maintenance(self.printer)

        self.assertEqual(self.printer.maintenance_is_need, False)
        self.assertEqual(self.printer.needed_maintenance, '')
        self.assertEqual(self.maintenance.program_maintenance_is_need, False)

    def test_repair_details(self):
        self.printer.maintenance_is_need = True
        self.printer.needed_maintenance = 'Требуется ремонт деталей принтера'
        self.maintenance.repair_details_is_need = True
        self.maintenance.repair_details(self.printer)

        self.assertEqual(self.printer.maintenance_is_need, False)
        self.assertEqual(self.printer.needed_maintenance, '')
        self.assertEqual(self.maintenance.repair_details_is_need, False)


if __name__ == "__main__":
    unittest.main()