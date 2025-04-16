from typing import List, Dict, Union
from random import randint

from Maintenance import Maintenance
from PrintDocument import PrintDocument
from Page import Page
from Ink import Ink
from Cartridge import Cartridge
from Paper import Paper
from Printer import Printer
from Driver import Driver
from common_functions import correct_input, handling_value_error

def create_ink(cartridge_volume: float) -> Ink:
    ink_material: str = correct_input(['водяные', 'масляные', 'твердые', 'сублимационные'],
                                         'Введите материал чернил для принтера'
                                                  '(водяные, масляные, твердые, сублимационные): ')
    while True:
        ink_volume: float = handling_value_error('Введите объем чернил для принтера(в мл): ',
                                                 'float')
        if ink_volume < 0:
            print('Некорректный ввод!(объем чернил не может быть меньше 0)')
        elif cartridge_volume >= ink_volume:
            ink: Ink = Ink(ink_material, ink_volume)
            break
        else:
            print('Объем чернил превышает объем картриджа!')
    return ink

def create_cartridge() -> Cartridge:
    while True:
        cartridge_volume: float = handling_value_error('Введите объем картриджа(в мл): ',
                                                     'float')
        if cartridge_volume <= 0:
            print('Некорректный ввод!(объем картриджа не может быть меньше или равен 0)')
        else:
            break
    ink: Ink = create_ink(cartridge_volume)
    cartridge: Cartridge = Cartridge(ink, cartridge_volume)
    return cartridge

def create_paper() -> List[Paper]:
    paper: List[Paper] = []
    for i in range(7):
        while True:
            paper_num: int = handling_value_error(f'Введите количество бумаги принтера формата А{i}: ',
                                                 'int')
            if paper_num < 0:
                print('Некорректный ввод!(бумаги не может быть меньше 0)')
            else:
                break
        for j in range(paper_num):
            paper.append(Paper('А' + str(i)))
    return paper

def create_printer() -> Printer:
    model: str = input('Введите модель принтера: ')
    pr_type: str = correct_input(['черно-белый', 'цветной'],
                                     'Введите тип принтера'
                                              '(черно-белый/цветной): ')
    cartridge: Cartridge = create_cartridge()
    paper: List[Paper] = create_paper()
    printer: Printer = Printer(cartridge, paper, model, pr_type)
    return printer

def choice_document(documents: List[PrintDocument]) -> PrintDocument:
    while True:
        doc_choice: int = handling_value_error('Создайте документ для печати '
                                                         'или выберите из имеющихся'
                                                         '(1 - создать, 2 - выбрать): ',
                                             'int')
        if doc_choice == 1:
            print('Создание документа для печати')
            doc_type: str = correct_input(['текст', 'изображение'],
                                              'Введите тип документа'
                                                       '(текст/изображение): ')
            doc_name: str = input('Введите имя документа: ')
            doc_pages: List[Page] = []
            if doc_type == 'текст':
                doc_pages_num: int = handling_value_error('Введите количество страниц документа: ',
                                                          'int')
                if doc_pages_num == 0:
                    doc_pages.append(Page(''))
                for i in range(doc_pages_num):
                    page_content: str = input(f'Введите содержимое {i + 1}-ой страницы: ')
                    doc_pages.append(Page(page_content))
            else:
                doc_pages.append(Page(f'изображение "{doc_name}"'))
            document: PrintDocument = PrintDocument(doc_type, doc_name, doc_pages)
            documents.append(document)
            break
        if doc_choice == 2 and documents != []:
            for i in range(len(documents)):
                print(f'{i + 1}. {documents[i].name}')
            doc_num: int = handling_value_error('Выберите документ(введите его номер): ',
                                                'int')
            if 1 <= doc_num <= len(documents):
                document: PrintDocument = documents[doc_num - 1]
                break
            else:
                print('Документа под таким номером нет!')
        if doc_choice == 2 and documents == []:
            print('Документов для выбора нет!')
        else:
            print('Введено число не от 1 до 2!')
    return document

def printing_document(printer: Printer, maintenance: Maintenance, documents: List[PrintDocument]) -> None:
    if printer.maintenance_is_need == True:
        print(printer.needed_maintenance)
    elif randint(1, 7) == 1:
        printer.maintenance_is_need = True
        maintenance.diagnose(printer)
    else:
        document: PrintDocument = choice_document(documents)
        print('Настройка параметров печати')
        parameters: Dict[str, Union[str, int, List[Page]]] = Driver.print_parameters(document)
        result: List[Page] = printer.print_document(document, parameters)
        if result != []:
            print('Напечатанные страницы:')
            for i in range(len(result)):
                print(f'Страница {i + 1}: {result[i].content}')

def driver_control(printer: Printer, driver: Driver, maintenance: Maintenance, documents: List[PrintDocument]) -> None:
    while True:
        print('1. Посмотреть очередь печати')
        print('2. Добавить документ в очередь печати')
        print('3. Удалить документ из очереди печати')
        print('4. Печатать документ из очереди печати')
        print('5. Печатать все документы из очереди печати')
        print('6. Выход из меню драйвера')
        ch: int = handling_value_error('Выберите действие(введите число): ', 'int')
        match ch:
            case 1:
                print('Очередь печати:')
                for i in range(len(driver.queue)):
                    print(f'{i + 1}. {driver.queue[i]['document'].name}')
                print()
            case 2:
                document: PrintDocument = choice_document(documents)
                print('Настройка параметров печати')
                parameters: Dict[str, Union[str, int, List[Page]]] = Driver.print_parameters(document)
                driver.add_document(document, parameters)
            case 3:
                while True:
                    doc_num: int = handling_value_error('Введите номер документа для удаления: ',
                                                        'int')
                    if driver.delete_document(doc_num) == True:
                        break
            case 4:
                print_document_from_queue(printer, driver, maintenance)
            case 5:
                print_all_documents_from_queue(printer, driver, maintenance)
            case 6:
                break
            case _:
                print('Введено число не от 1 до 6!')

def print_document_from_queue(printer: Printer, driver: Driver, maintenance: Maintenance) -> None:
    while True:
        if printer.maintenance_is_need == True:
            print(printer.needed_maintenance)
            break
        elif randint(1, 7) == 1:
            printer.maintenance_is_need = True
            maintenance.diagnose(printer)
            break
        else:
            doc_num: int = handling_value_error('Введите номер документа для печати: ',
                                              'int')
            result: List[Page] = driver.print_document(doc_num)
            if result != []:
                print('Напечатанные страницы:')
                for i in range(len(result)):
                    print(f'Страница {i + 1}: {result[i].content}')
                break
            else:
                pass

def print_all_documents_from_queue(printer: Printer, driver: Driver, maintenance: Maintenance) -> None:
    result: List[List[Page]] = driver.print_all_documents(printer, maintenance)
    if result != []:
        print('Напечатанные страницы:')
        for i in range(len(result)):
            print(f'Документ {i + 1}')
            for j in range(len(result[i])):
                print(f'Страница {j + 1}: {result[i][j].content}')

def change_materials(printer: Printer) -> None:
    print('1. Замена картриджа')
    print('2. Замена бумаги')
    print('3. Замена чернил')
    ch: int = handling_value_error('Выберите действие(введите число): ', 'int')
    match ch:
        case 1:
            new_cartridge: Cartridge = create_cartridge()
            printer.cartridge = new_cartridge
        case 2:
            change_paper(printer)
        case 3:
            change_ink(printer)
        case _:
            print('Введено число не от 1 до 3!')

def change_paper(printer: Printer) -> None:
    while True:
        ch: int = handling_value_error('Выберите действие(введите число: '
                                                 '1 - добавить бумагу, '
                                                 '2 - заменить полностью): ',
                                     'int')
        if ch == 1:
            new_paper: List[Paper] = create_paper()
            printer.paper += new_paper
            break
        if ch == 2:
            new_paper: List[Paper] = create_paper()
            printer.paper = new_paper
            break
        else:
            print('Введено число не от 1 до 2!')

def change_ink(printer: Printer) -> None:
    while True:
        ch: int = handling_value_error('Выберите действие(введите число: '
                                                 '1 - добавить чернила, '
                                                 '2 - заменить полностью): ',
                                     'int')
        if ch == 1:
            while True:
                new_ink_volume = handling_value_error('Введите объем чернил для дополнения(в мл): ',
                                                      'float')
                if new_ink_volume < 0:
                    print('Некорректный ввод!(объем чернил не может быть меньше 0)')
                elif printer.cartridge.ink.volume + new_ink_volume > printer.cartridge.volume:
                    print('Новый объем чернил превышает объем картриджа!')
                else:
                    printer.cartridge.fill_ink(new_ink_volume)
                    break
            break
        if ch == 2:
            print('Создание новых чернил')
            new_ink: Ink = create_ink(printer.cartridge.volume)
            printer.cartridge.change_ink(new_ink)
            break
        else:
            print('Введено число не от 1 до 2!')

def repair_and_maintenance(printer: Printer, maintenance: Maintenance) -> None:
    if printer.maintenance_is_need == True:
        print('1. Очистка принтера')
        print('2. Программное обслуживание принтера')
        print('3. Ремонт деталей принтера')
        ch: int = handling_value_error('Выберите действие(введите число): ', 'int')
        match ch:
            case 1:
                maintenance.clean(printer)
            case 2:
                maintenance.program_maintenance(printer)
            case 3:
                maintenance.repair_details(printer)
            case _:
                print('Введено число не от 1 до 3!')
    else:
        print('Обслуживание принтера не требуется!')

def check_materials(printer: Printer) -> None:
    print('1. Посмотреть состояние картриджа')
    print('2. Посмотреть количество бумаги')
    print('3. Посмотреть объем чернил')
    ch: int = handling_value_error('Выберите действие(введите число): ', 'int')
    match ch:
        case 1:
            print(f'Картриджа хватит еще на {5 - printer.cartridge.ink_filling} заливки чернил')
        case 2:
            for i in range(7):
                print(f'Количество бумаги формата A{str(i)}: '
                      f'{printer.find_number_of_paper_in_format('А' + str(i))}')
        case 3:
            print(f'В картридже {printer.cartridge.ink.volume} мл чернил')
        case _:
            print('Введено число не от 1 до 3!')