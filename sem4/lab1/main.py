from functions import *

print('Создание принтера')
printer: Printer = create_printer()
driver: Driver = Driver(printer)
maintenance: Maintenance = Maintenance()
documents: List[PrintDocument] = []
while True:
    print('1. Печать документа')
    print('2. Управление печатью через драйвер')
    print('3. Замена расходных материалов')
    print('4. Ремонт и обслуживание')
    print('5. Посмотреть количество расходных материалов')
    print('6. Выход из меню')
    choice: int = handling_value_error('Выберите действие(введите число): ', 'int')
    match choice:
        case 1:
            printing_document(printer, maintenance, documents)
        case 2:
            driver_control(printer, driver, maintenance, documents)
        case 3:
            change_materials(printer)
        case 4:
            repair_and_maintenance(printer, maintenance)
        case 5:
            check_materials(printer)
        case 6:
            break
        case _:
            print('Введено число не от 1 до 6!')