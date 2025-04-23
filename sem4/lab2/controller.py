from tkinter import *
from tkinter import ttk
from tkinter import filedialog
from tkinter.messagebox import showerror, showinfo

from model import Model

RECORDS_DIR = r'C:\Users\Ruslan\Documents\ППОИС\sem4\lab2\records'

class Controller:
    def __init__(self):
        pass

    @staticmethod
    def create_table(model, window, rel_x, rel_y, number_of_records_on_page):
        if model.table_var["table"] is not None:
            model.table_var["table"].destroy()
        columns = ('tournament', 'date', 'sport', 'winner', 'tournament_prize', 'winner_prize')
        table = ttk.Treeview(window, columns=columns, show='headings', height=number_of_records_on_page)
        table.place(relwidth=1.0, relx=rel_x, rely=rel_y)

        table.heading('tournament', text='Название турнира', anchor=W)
        table.heading('date', text='Дата проведения', anchor=W)
        table.heading('sport', text='Название вида спорта', anchor=W)
        table.heading('winner', text='ФИО победителя', anchor=W)
        table.heading('tournament_prize', text='Размер призовых турнира', anchor=W)
        table.heading('winner_prize', text='Заработок победителя', anchor=W)

        index = (model.active_page.get() - 1) * number_of_records_on_page
        for i in range(index, index + number_of_records_on_page):
            if i < len(model.records):
                table.insert("", END, values=list(model.records[i].values()))
        model.table_var["table"] = table

    @staticmethod
    def ok(model: Model, window, rel_x, rel_y, input_number_of_records_on_page):
        if '-' in input_number_of_records_on_page.get():
            showerror(title='Ошибка', message='Число записей на странице должно быть больше нуля!')
            return
        try:
            model.last_page.set((len(model.records) - 1) // int(input_number_of_records_on_page.get()) + 1)
        except ValueError:
            showerror(title='Ошибка', message='Введено не целое число!')
            return
        except ZeroDivisionError:
            showerror(title='Ошибка', message='Число записей на странице должно быть больше нуля!')
            return
        Controller.create_table(model, window, rel_x, rel_y, int(input_number_of_records_on_page.get()))

    @staticmethod
    def to_first_page(model: Model, window, rel_x, rel_y, input_number_of_records_on_page):
        if len(model.records) == 0:
            return
        model.active_page.set(1)
        Controller.create_table(model, window, rel_x, rel_y, int(input_number_of_records_on_page.get()))

    @staticmethod
    def to_prev_page(model: Model, window, rel_x, rel_y, input_number_of_records_on_page):
        if len(model.records) == 0:
            return
        if model.active_page.get() == 1:
            return
        model.active_page.set(model.active_page.get() - 1)
        Controller.create_table(model, window, rel_x, rel_y, int(input_number_of_records_on_page.get()))

    @staticmethod
    def to_next_page(model: Model, window, rel_x, rel_y, input_number_of_records_on_page):
        if len(model.records) == 0:
            return
        if model.active_page.get() == model.last_page.get():
            return
        model.active_page.set(model.active_page.get() + 1)
        Controller.create_table(model, window, rel_x, rel_y, int(input_number_of_records_on_page.get()))

    @staticmethod
    def to_last_page(model: Model, window, rel_x, rel_y, input_number_of_records_on_page):
        if len(model.records) == 0:
            return
        model.active_page.set(model.last_page.get())
        Controller.create_table(model, window, rel_x, rel_y, int(input_number_of_records_on_page.get()))

    @staticmethod
    def change_entry_state(entry, en_var1, en_var2, en_var3):
        if en_var1.get() == 1 or en_var2.get() == 1 or en_var3.get() == 1:
            entry.config(state='normal')
        else:
            entry.delete(0, 'end')
            entry.config(state='disabled')

    @staticmethod
    def open_file(model: Model):
        filepath = filedialog.askopenfilename(title = 'Открытие файла', defaultextension = 'txt', initialdir = RECORDS_DIR)
        model.open_file(filepath)

    @staticmethod
    def save_file(model: Model):
        filepath = filedialog.asksaveasfilename(title = 'Сохранение файла', defaultextension = 'xml', initialdir = RECORDS_DIR)
        model.save_file(filepath)

    @staticmethod
    def add_record(model: Model, inputs):
        model.add_record(inputs)

    @staticmethod
    def find_records(model: Model, records, window, number_of_records_on_page: Entry, inputs):
        model = model.find_records(records, inputs)
        Controller.create_table(model, window, 0.001, 0.3, int(number_of_records_on_page.get()))

    @staticmethod
    def delete_records(model: Model, inputs):
        k = model.delete_records(inputs)
        showinfo(title='Информация', message=f'Количество удаленных записей: {k}')
