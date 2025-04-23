from tkinter import *
from tkinter.messagebox import showerror
from datetime import date
from xml.dom import minidom
import xml.sax

from records_handler import RecordsHandler

class Model:
    def __init__(self):
        self.records = []
        self.number_of_records = IntVar(value=len(self.records))
        self.sports = ['']
        self.active_page, self.last_page = IntVar(value=1), IntVar(value=1)
        self.table_var = {"table": None}

    @staticmethod
    def get_fio(fio, en_var1, en_var2, en_var3):
        parts = fio.split(' ')
        result = ''
        if en_var1 == 1:
            result = result + parts[0]
        if en_var2 == 1:
            result = result + ' ' + parts[1]
        if en_var3 == 1:
            result = result + ' ' + parts[2]
        if len(result) != 0 and result[0] == ' ':
            return result[1:]
        return result

    def delete_records(self, inputs):
        name = inputs[0].get()
        if inputs[1][0].get() == inputs[1][1].get() == inputs[1][2].get() == '':
            date_ = ''
        else:
            try:
                date_ = date(int(inputs[1][0].get()), int(inputs[1][1].get()), int(inputs[1][2].get()))
            except ValueError:
                showerror(title='Ошибка', message='Дата введена некорректно!')
                return
        sport = inputs[2].get()
        fio = inputs[3][0].get()
        if inputs[4][0].get() == '' and inputs[4][1].get() == '':
            prize1, prize2 = 0.0, 0.0
        elif (inputs[4][0].get() == '' and inputs[4][1].get() != '') or \
             (inputs[4][0].get() != '' and inputs[4][1].get() == ''):
            showerror(title='Ошибка', message='Должны быть введены либо оба предела, либо ни одного!')
            return
        else:
            try:
                prize1 = float(inputs[4][0].get())
                prize2 = float(inputs[4][1].get())
                if prize1 > prize2:
                    showerror(title='Ошибка', message='Нижний предел должен быть меньше верхнего!')
                    return
            except ValueError:
                showerror(title='Ошибка', message='Введено не число!')
                return
        if inputs[5][0].get() == '' and inputs[5][1].get() == '':
            winner_prize1, winner_prize2 = 0.0, 0.0
        elif (inputs[5][0].get() == '' and inputs[5][1].get() != '') or \
             (inputs[5][0].get() != '' and inputs[5][1].get() == ''):
            showerror(title='Ошибка', message='Должны быть введены либо оба предела, либо ни одного!')
            return
        else:
            try:
                winner_prize1 = float(inputs[5][0].get())
                winner_prize2 = float(inputs[5][1].get())
                if winner_prize1 > winner_prize2:
                    showerror(title='Ошибка', message='Нижний предел должен быть меньше(или равен) верхнего!')
                    return
            except ValueError:
                showerror(title='Ошибка', message='Введено не число!')
                return
        k = 0
        for record in self.records[:]:
            if name == date_ == sport == fio == '' and prize1 == prize2 == winner_prize1 == winner_prize2 == 0.0:
                continue
            if (name == record['tournament'] or name == '') and \
                  (date_ == record['date'] or date_ == '') and \
                  (sport == record['sport'] or sport == '') and \
                  (fio == self.get_fio(record['winner'], inputs[3][1].get(),
                   inputs[3][2].get(), inputs[3][3].get()) or fio == '') and \
                  (prize1 <= record['tournament_prize'] <= prize2 or prize1 == prize2 == 0.0) and \
                  (winner_prize1 <= record['winner_prize'] <= winner_prize2 or
                   winner_prize1 == winner_prize2 == 0.0):
                self.records.remove(record)
                k += 1
                self.number_of_records.set(self.number_of_records.get() - 1)
        return k

    def find_records(self, records, inputs):
        self.records.clear()
        name = inputs[0].get()
        if inputs[1][0].get() == inputs[1][1].get() == inputs[1][2].get() == '':
            date_ = ''
        else:
            try:
                date_ = date(int(inputs[1][0].get()), int(inputs[1][1].get()), int(inputs[1][2].get()))
            except ValueError:
                showerror(title='Ошибка', message='Дата введена некорректно!')
                return
        sport = inputs[2].get()
        fio = inputs[3][0].get()
        if inputs[4][0].get() == '' and inputs[4][1].get() == '':
            prize1, prize2 = 0.0, 0.0
        elif (inputs[4][0].get() == '' and inputs[4][1].get() != '') or \
                (inputs[4][0].get() != '' and inputs[4][1].get() == ''):
            showerror(title='Ошибка', message='Должны быть введены либо оба предела, либо ни одного!')
            return
        else:
            try:
                prize1 = float(inputs[4][0].get())
                prize2 = float(inputs[4][1].get())
                if prize1 > prize2:
                    showerror(title='Ошибка', message='Нижний предел должен быть меньше верхнего!')
                    return
            except ValueError:
                showerror(title='Ошибка', message='Введено не число!')
                return
        if inputs[5][0].get() == '' and inputs[5][1].get() == '':
            winner_prize1, winner_prize2 = 0.0, 0.0
        elif (inputs[5][0].get() == '' and inputs[5][1].get() != '') or \
                (inputs[5][0].get() != '' and inputs[5][1].get() == ''):
            showerror(title='Ошибка', message='Должны быть введены либо оба предела, либо ни одного!')
            return
        else:
            try:
                winner_prize1 = float(inputs[5][0].get())
                winner_prize2 = float(inputs[5][1].get())
                if winner_prize1 > winner_prize2:
                    showerror(title='Ошибка', message='Нижний предел должен быть меньше(или равен) верхнего!')
                    return
            except ValueError:
                showerror(title='Ошибка', message='Введено не число!')
                return
        for record in records:
            if name == date_ == sport == fio == '' and prize1 == prize2 == winner_prize1 == winner_prize2 == 0.0:
                continue
            if (name == record['tournament'] or name == '') and \
                    (date_ == record['date'] or date_ == '') and \
                    (sport == record['sport'] or sport == '') and \
                    (fio == self.get_fio(record['winner'], inputs[3][1].get(),
                                    inputs[3][2].get(), inputs[3][3].get()) or fio == '') and \
                    (prize1 <= record['tournament_prize'] <= prize2 or prize1 == prize2 == 0.0) and \
                    (winner_prize1 <= record['winner_prize'] <= winner_prize2 or
                     winner_prize1 == winner_prize2 == 0.0):
                self.records.append(record)
        self.number_of_records.set(len(self.records))
        return self

    def add_record(self, inputs):
        tournament = inputs[0].get()
        if tournament == '':
            showerror(title='Ошибка', message='Название турнира не введено!')
            return
        try:
            day = inputs[1][0].get()
            if day == '':
                showerror(title='Ошибка', message='День не введен!')
                return
            month = inputs[1][1].get()
            if month == '':
                showerror(title='Ошибка', message='Месяц не введен!')
                return
            year = inputs[1][2].get()
            if year == '':
                showerror(title='Ошибка', message='Год не введен!')
                return
            d = date(int(year), int(month), int(day))
        except ValueError:
            showerror(title='Ошибка', message=f'В {month}-ом месяце нет {day} дня(ей)!')
            return
        sport = inputs[2].get()
        if sport == '':
            showerror(title='Ошибка', message='Название вида спорта не введено!')
            return
        if sport not in self.sports:
            self.sports.append(sport)
        winner = inputs[3].get()
        if winner == '':
            showerror(title='Ошибка', message='ФИО победителя не введено!')
            return
        if len(winner.split(' ')) != 3:
            showerror(title='Ошибка', message='ФИО победителя введено некорректно!')
            return
        try:
            tournament_prize = float(inputs[4].get())
        except ValueError:
            showerror(title='Ошибка', message='Введено не число(размер призовых турнира)!')
            return
        record = {'tournament': tournament, 'date': d, 'sport': sport, 'winner': winner,
                  'tournament_prize': tournament_prize, 'winner_prize': tournament_prize * 0.6}
        self.records.append(record)
        self.number_of_records.set(len(self.records))


    def open_file(self, filepath):
        if filepath != '' and filepath[-4:] == '.xml':
            handler = RecordsHandler()
            parser = xml.sax.make_parser()
            parser.setContentHandler(handler)
            parser.parse(filepath)
            self.records.clear()
            self.records.extend(handler.records)
            self.number_of_records.set(len(self.records))
            for record in self.records:
                if record['sport'] not in self.sports:
                    self.sports.append(record['sport'])
                record['tournament_prize'] = float(record['tournament_prize'])
                record['winner_prize'] = float(record['winner_prize'])

    def save_file(self, filepath):
        if filepath != '' and filepath[-4:] == '.xml':
            doc = minidom.Document()
            root = doc.createElement("records")
            doc.appendChild(root)
            for record in self.records:
                record_element = doc.createElement("record")
                for key, value in record.items():
                    element = doc.createElement(key)
                    element.appendChild(doc.createTextNode(str(value)))
                    record_element.appendChild(element)
                root.appendChild(record_element)
            with open(filepath, "w", encoding="utf-8") as file:
                file.write(doc.toprettyxml(indent="  "))