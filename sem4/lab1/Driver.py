from random import randint
from typing import List, Dict, Union

from Printer import Printer
from PrintDocument import PrintDocument
from Page import Page
from Maintenance import Maintenance
from common_functions import correct_input, parse_number_of_pages, handling_value_error

class Driver:
    def __init__(self, printer: Printer) -> None:
        self.printer = printer
        self.queue: List[Dict[str, Union[PrintDocument, Dict[str, Union[str, int, List[Page]]]]]] = []

    def add_document(self, document: PrintDocument, parameters: Dict[str, Union[str, int, List[Page]]]) -> None:
        for i in range(parameters['copy']):
            new_parameters: Dict[str, Union[str, int, List[Page]]] = parameters.copy()
            new_parameters['copy'] = 1
            item: Dict[str, Union[PrintDocument, Dict[str, Union[str, int, List[Page]]]]] = \
                  {'document': document, 'parameters': new_parameters}
            self.queue.append(item)

    def delete_document(self, number: int) -> bool:
        if 1 <= number <= len(self.queue):
            self.queue.pop(number - 1)
            return True
        else:
            print('Документа под таким номером нет!')
            return False

    def print_document(self, number: int) -> List[Page]:
        if len(self.queue) < number < 1:
            print('Документа под таким номером нет!')
            return []
        document = self.queue[number - 1]
        result = self.printer.print_document(document['document'], document['parameters'])
        if result != []:
            self.queue.pop(number - 1)
        return result

    def print_all_documents(self, printer: Printer, maintenance: Maintenance) -> List[List[Page]]:
        result: List[List[Page]] = []
        i: int = 0
        while i < len(self.queue):
            if printer.maintenance_is_need == True:
                print(printer.needed_maintenance)
                break
            elif randint(1, 7) == 1:
                printer.maintenance_is_need = True
                maintenance.diagnose(printer)
                break
            else:
                document = self.queue[i]
                inter_result: List[Page] = self.printer.print_document(document['document'], document['parameters'])
                if inter_result != []:
                    result.append(inter_result)
                    self.queue.pop(i)
                else:
                    break
        return result

    @staticmethod
    def print_parameters(document: PrintDocument) -> Dict[str, Union[str, int, List[Page]]]:
        parameters: Dict[str, Union[str, int, List[Page]]] = {}
        pages: List[Page] = []
        if document.type == 'текст':
            choice: int = 0
            while choice != 1 and choice != 2:
                choice = handling_value_error('Выберите количество печатаемых страниц'
                                                       '(1 - все страницы, 2 - определенные страницы): ',
                                              'int')
                match choice:
                    case 1:
                        pages = document.pages
                    case 2:
                        while True:
                            numbers: str = input('Введите номера печатаемых страниц через запятую(например, 1,5) '
                                                  'или через дефис(например, 3-7)(общий пример: 1,2,4-6,9):')
                            pages = parse_number_of_pages(numbers, document.pages)
                            if pages != []:
                                break
                    case _:
                        print('Введено число не от 1 до 2! Повторите ввод')
            parameters.update({'pages': pages})
            side_print: str = correct_input(['односторонняя', 'двусторонняя'],
                                                'Выберите тип печати(односторонняя/двусторонняя): ')
            parameters.update({'side_print': side_print})
        format: str = correct_input(['А0', 'А1', 'А2', 'А3', 'А4', 'А5', 'А6'],
                                   'Введите формат бумаги на русском языке'
                                             '(A0,A1,A2,A3,A4,A5,A6): ')
        parameters.update({'format': format})
        orientation: str = correct_input(['книжная', 'альбомная'],
                                             'Выберите ориентацию печати'
                                                      '(книжная/альбомная): ')
        parameters.update({'orientation': orientation})
        while True:
            copy: int = handling_value_error('Введите количество копий: ', 'int')
            if copy < 1:
                print('Количество копий должно быть больше 0!')
            else:
                break
        parameters.update({'copy': copy})
        return parameters