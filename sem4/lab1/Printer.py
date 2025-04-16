from typing import List, Dict, Union

from Cartridge import Cartridge
from Paper import Paper
from Page import Page
from PrintDocument import PrintDocument

class Printer:
    def __init__(self, cartridge: Cartridge, paper: List[Paper], model: str, pr_type: str) -> None:
        self.cartridge = cartridge
        self.paper = paper
        self.model = model
        self.type = pr_type
        self.maintenance_is_need: bool = False
        self.needed_maintenance: str = ''

    def find_number_of_paper_in_format(self, format: str) -> int:
        number: int = 0
        for i in self.paper:
            if i.format == format:
                number += 1
        return number

    def delete_pages_in_format(self, format: str, copy: int) -> None:
        for i in range(copy):
            paper: Paper = Paper(format)
            if paper in self.paper:
                self.paper.remove(paper)

    def print_document(self, document: PrintDocument, parameters: Dict[str, Union[str, int, List[Page]]]) -> List[Page]:
        result: List[Page] = []
        if self.cartridge.ink_filling <= 5:
            if document.type == 'изображение':
                if parameters['copy'] <= self.find_number_of_paper_in_format(parameters['format']):
                    if parameters['copy'] * self.cartridge.ink_image_consumption <= self.cartridge.ink.volume:
                        self.cartridge.ink.volume -= parameters['copy'] * self.cartridge.ink_image_consumption
                        self.delete_pages_in_format(parameters['format'], parameters['copy'])
                        for i in range(parameters['copy']):
                            result.append(document.pages[0])
                    else:
                        print('Недостаточно чернил!')
                else:
                    print(f'Недостаточно страниц формата {parameters['format']}!')
            if document.type == 'текст':
                number_of_paper: int = len(parameters['pages'])
                if parameters['side_print'] == 'двусторонняя':
                    number_of_paper = number_of_paper // 2 + 1
                number_of_paper *= parameters['copy']
                number_of_pages: int = len(parameters['pages']) * parameters['copy']
                if number_of_paper <= self.find_number_of_paper_in_format(parameters['format']):
                    if number_of_pages * self.cartridge.ink_text_consumption <= self.cartridge.ink.volume:
                        self.cartridge.ink.volume -= number_of_pages * self.cartridge.ink_text_consumption
                        self.delete_pages_in_format(parameters['format'], number_of_paper)
                        for i in range(parameters['copy']):
                            for page in parameters['pages']:
                                result.append(page)
                    else:
                        print('Недостаточно чернил!')
                else:
                    print(f'Недостаточно страниц формата {parameters['format']}!')
        else:
            print('Необходимо сменить картридж принтера!')
        return result