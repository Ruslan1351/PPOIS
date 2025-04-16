from random import randint

from Printer import Printer

class Maintenance:
    def __init__(self) -> None:
        self.clean_is_need: bool = False
        self.program_maintenance_is_need: bool = False
        self.repair_details_is_need: bool = False

    def diagnose(self, printer: Printer) -> None:
        repair_choice: int = randint(1, 10)
        if repair_choice < 5:
            print('Требуется очистка принтера!')
            self.clean_is_need = True
            printer.needed_maintenance = 'Требуется очистка принтера!'
            return
        if 4 < repair_choice < 9:
            print('Требуется программное обслуживание принтера!')
            self.program_maintenance_is_need = True
            printer.needed_maintenance = 'Требуется программное обслуживание принтера!'
            return
        if 8 < repair_choice < 11:
            print('Требуется ремонт деталей принтера!')
            self.repair_details_is_need = True
            printer.needed_maintenance = 'Требуется ремонт деталей принтера!'
            return

    def clean(self, printer: Printer) -> None:
        if self.clean_is_need == True:
            print('Очитска принтера выполнена')
            self.clean_is_need = False
            printer.maintenance_is_need = False
            printer.needed_maintenance = ''
        else:
            print('Очистка принтера не требуется!')

    def program_maintenance(self, printer: Printer) -> None:
        if self.program_maintenance_is_need == True:
            print('Программное обслуживание принтера выполнено')
            self.program_maintenance_is_need = False
            printer.maintenance_is_need = False
            printer.needed_maintenance = ''
        else:
            print('Программное обслуживание не требуется!')

    def repair_details(self, printer: Printer) -> None:
        if self.repair_details_is_need == True:
            print('Ремонт деталей принтера выполнен')
            self.repair_details_is_need = False
            printer.maintenance_is_need = False
            printer.needed_maintenance = ''
        else:
            print('Ремонт деталей принтера не требуется!')