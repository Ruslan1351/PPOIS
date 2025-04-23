from tkinter import *
from tkinter import ttk

from model import Model
from controller import Controller

class View:
    def __init__(self):
        self.window = Tk()
        self.main_model = Model()
        self.search_model = Model()
        self.controller = Controller()

    def main_window(self):
        self.window.title('Массив записей')
        self.window.geometry('1525x790+0+0')
        self.window.resizable(False, False)
        self.window.option_add("*tearOff", FALSE)

        records_menu = Menu()
        records_menu.add_command(label='Добавить записи', command=self.add_records_window)
        records_menu.add_command(label='Открыть файл с записями', command=lambda: self.controller.open_file(self.main_model))
        records_menu.add_command(label='Сохранить файл с записями', command=lambda: self.controller.save_file(self.main_model))

        main_menu = Menu()
        main_menu.add_cascade(label='Работа с массивом записей', menu=records_menu)
        main_menu.add_cascade(label='Поиск записей', command=self.search_records_window)
        main_menu.add_cascade(label='Удаление записей', command=self.delete_records_window)
        self.window.config(menu=main_menu)

        number_of_records_on_page = Label(text='Введите количество записей на странице:', font=('Arial', 13))
        number_of_records_on_page.place(relx=0.105, rely=0.02)
        input_number_of_records_on_page = Entry(font=('Arial', 11))
        input_number_of_records_on_page.insert(0, '0')
        input_number_of_records_on_page.place(width=35, height=25, relx=0.325, rely=0.02)
        button_ok = Button(text='ОК', font=('Arial', 12), command=lambda: self.controller.ok(self.main_model, self.window,0.001,
                                                                                             0.1, input_number_of_records_on_page))
        button_ok.place(width=35, relx=0.35, rely=0.02)

        label1 = Label(text='Количество записей в таблице - ', font=('Arial', 13))
        label1.place(relx=0.6, rely=0.02)
        label_number_of_records = Label(textvariable=self.main_model.number_of_records, font=('Arial', 13))
        label_number_of_records.place(relx=0.768, rely=0.02)

        button_first_page = Button(text='1', font=('Arial', 12), command=lambda: self.controller.to_first_page(self.main_model, self.window,
                                                                                                               0.001,0.1,
                                                                                                               input_number_of_records_on_page))
        button_first_page.place(width=25, relx=0.42, rely=0.02)
        button_prev_page = Button(text='<', font=('Arial', 12), command=lambda: self.controller.to_prev_page(self.main_model, self.window,
                                                                                                               0.001,0.1,
                                                                                                               input_number_of_records_on_page))
        button_prev_page.place(width=25, relx=0.45, rely=0.02)
        label2 = Label(text='стр. ', font=('Arial', 12))
        label2.place(relx=0.48, rely=0.025)
        label_active_page = Label(textvariable=self.main_model.active_page, font=('Arial', 12))
        label_active_page.place(relx=0.5, rely=0.025)
        button_next_page = Button(text='>', font=('Arial', 12), command=lambda: self.controller.to_next_page(self.main_model, self.window,
                                                                                                               0.001,0.1,
                                                                                                               input_number_of_records_on_page))
        button_next_page.place(width=25, relx=0.52, rely=0.02)
        button_last_page = Button(textvariable=self.main_model.last_page, font=('Arial', 12),
                                  command=lambda: self.controller.to_last_page(self.main_model, self.window,
                                                                               0.001,0.1,
                                                                               input_number_of_records_on_page))
        button_last_page.place(width=35, relx=0.55, rely=0.02)

        self.window.mainloop()

    @staticmethod
    def dismiss(subwindow):
        subwindow.grab_release()
        subwindow.destroy()

    def add_records_window(self):
        subwindow = Toplevel()
        subwindow.title('Добавление записей')
        subwindow.geometry('760x400+400+200')
        subwindow.resizable(False, False)
        subwindow.protocol('WM_DELETE_WINDOW', lambda: self.dismiss(subwindow))
        subwindow.grab_set()

        label1 = Label(subwindow, text='Введите название турнира: ', font=('Arial', 14))
        label1.place(relx=0.01, rely=0.0)
        input_name = Entry(subwindow, font=('Arial', 12))
        input_name.place(relwidth=0.55, relx=0.43, rely=0.0)

        label2 = Label(subwindow, text='Введите дату проведения турнира: ', font=('Arial', 14))
        label2.place(relx=0.01, rely=0.15)
        label_day = Label(subwindow, text='день:', font=('Arial', 14))
        label_day.place(relx=0.43, rely=0.15)
        input_day = ttk.Combobox(subwindow, values=[i for i in range(1, 32)], state='readonly', font=('Arial', 10))
        input_day.place(relwidth=0.06, relheight=0.065, relx=0.5, rely=0.15)
        label_month = Label(subwindow, text='месяц:', font=('Arial', 14))
        label_month.place(relx=0.6, rely=0.15)
        input_month = ttk.Combobox(subwindow, values=[i for i in range(1, 13)], state='readonly', font=('Arial', 10))
        input_month.place(relwidth=0.06, relheight=0.065, relx=0.69, rely=0.15)
        label_year = Label(subwindow, text='год:', font=('Arial', 14))
        label_year.place(relx=0.8, rely=0.15)
        input_year = ttk.Combobox(subwindow, values=[i for i in range(2000, 2026)], state='readonly', font=('Arial', 10))
        input_year.place(relwidth=0.08, relheight=0.065, relx=0.86, rely=0.15)

        label3 = Label(subwindow, text='Введите название вида спорта: ', font=('Arial', 14))
        label3.place(relx=0.01, rely=0.3)
        input_sport = Entry(subwindow, font=('Arial', 12))
        input_sport.place(relwidth=0.55, relx=0.43, rely=0.3)

        label4 = Label(subwindow, text='Введите ФИО победителя: ', font=('Arial', 14))
        label4.place(relx=0.01, rely=0.45)
        input_winner = Entry(subwindow, font=('Arial', 12))
        input_winner.place(relwidth=0.55, relx=0.43, rely=0.45)

        label5 = Label(subwindow, text='Введите размер призовых турнира: ', font=('Arial', 14))
        label5.place(relx=0.01, rely=0.6)
        input_prize = Entry(subwindow, font=('Arial', 12))
        input_prize.place(relwidth=0.55, relx=0.43, rely=0.6)

        button = Button(subwindow, text = 'ДОБАВИТЬ', font=('Arial', 20), command=lambda: self.controller.add_record(
                                                                                   self.main_model, [input_name,
                                                                                   [input_day, input_month, input_year],
                                                                                   input_sport, input_winner, input_prize]))
        button.place(relwidth = 0.6, relheight = 0.2, relx=0.2, rely=0.72)

    def search_records_window(self):
        subwindow = Toplevel()
        subwindow.title('Поиск записей')
        subwindow.geometry('1525x790+0+0')
        subwindow.resizable(False, False)
        subwindow.protocol('WM_DELETE_WINDOW', lambda: self.dismiss(subwindow))
        subwindow.grab_set()

        label1 = Label(subwindow, text='Введите название турнира: ', font=('Arial', 12))
        label1.place(relx=0.01, rely=0.01)
        input_name = Entry(subwindow, font=('Arial', 12))
        input_name.place(relwidth=0.13, relx=0.01, rely=0.05)

        label2 = Label(subwindow, text='Введите дату проведения турнира: ', font=('Arial', 12))
        label2.place(relx=0.15, rely=0.01)
        label_day = Label(subwindow, text='день', font=('Arial', 12))
        label_day.place(relx=0.15, rely=0.05)
        input_day = ttk.Combobox(subwindow, values=[''] + [i for i in range(1, 32)], state='readonly', font=('Arial', 10))
        input_day.place(relwidth=0.03, relx=0.15, rely=0.09)
        label_month = Label(subwindow, text='месяц', font=('Arial', 12))
        label_month.place(relx=0.2, rely=0.05)
        input_month = ttk.Combobox(subwindow, values=[''] + [i for i in range(1, 13)], state='readonly', font=('Arial', 10))
        input_month.place(relwidth=0.03, relx=0.2, rely=0.09)
        label_year = Label(subwindow, text='год', font=('Arial', 12))
        label_year.place(relx=0.25, rely=0.05)
        input_year = ttk.Combobox(subwindow, values=[''] + [i for i in range(2000, 2026)], state='readonly', font=('Arial', 10))
        input_year.place(relwidth=0.05, relx=0.25, rely=0.09)

        label3 = Label(subwindow, text='Выберите название вида спорта: ', font=('Arial', 12))
        label3.place(relx=0.33, rely=0.01)
        input_sport = ttk.Combobox(subwindow, values=self.main_model.sports, state='readonly')
        input_sport.place(relwidth=0.15, relx=0.33, rely=0.05)

        label4 = Label(subwindow, text='Введите ФИО победителя: ', font=('Arial', 12))
        label4.place(relx=0.5, rely=0.01)
        en1, en2, en3 = IntVar(), IntVar(), IntVar()
        check_button1 = Checkbutton(subwindow, text='фамилия', variable=en1, command=lambda: self.controller.change_entry_state(input_winner, en1, en2, en3))
        check_button1.place(relx=0.495, rely=0.05)
        check_button2 = Checkbutton(subwindow, text='имя', variable=en2, command=lambda: self.controller.change_entry_state(input_winner, en1, en2, en3))
        check_button2.place(relx=0.55, rely=0.05)
        check_button3 = Checkbutton(subwindow, text='отчество', variable=en3, command=lambda: self.controller.change_entry_state(input_winner, en1, en2, en3))
        check_button3.place(relx=0.59, rely=0.05)
        input_winner = Entry(subwindow, state='disabled', font=('Arial', 12))
        input_winner.place(relwidth=0.15, relx=0.49, rely=0.09)

        label5 = Label(subwindow, text='Введите размер призовых турнира: ', font=('Arial', 12))
        label5.place(relx=0.65, rely=0.01)
        label5_1 = Label(subwindow, text='нижний предел: ', font=('Arial', 12))
        label5_1.place(relx=0.65, rely=0.05)
        input_prize1 = Entry(subwindow, font=('Arial', 12))
        input_prize1.place(relwidth=0.08, relx=0.735, rely=0.05)
        label5_2 = Label(subwindow, text='верхний предел: ', font=('Arial', 12))
        label5_2.place(relx=0.65, rely=0.09)
        input_prize2 = Entry(subwindow, font=('Arial', 12))
        input_prize2.place(relwidth=0.08, relx=0.735, rely=0.09)

        label6 = Label(subwindow, text='Введите заработок победителя: ', font=('Arial', 12))
        label6.place(relx=0.83, rely=0.01)
        label6_1 = Label(subwindow, text='нижний предел: ', font=('Arial', 12))
        label6_1.place(relx=0.83, rely=0.05)
        input_winner_prize1 = Entry(subwindow, font=('Arial', 12))
        input_winner_prize1.place(relwidth=0.08, relx=0.915, rely=0.05)
        label6_2 = Label(subwindow, text='верхний предел: ', font=('Arial', 12))
        label6_2.place(relx=0.83, rely=0.09)
        input_winner_prize2 = Entry(subwindow, font=('Arial', 12))
        input_winner_prize2.place(relwidth=0.08, relx=0.915, rely=0.09)

        number_of_records_on_page = Label(subwindow, text='Введите количество записей на странице:', font=('Arial', 12))
        number_of_records_on_page.place(relx=0.101, rely=0.24)
        input_number_of_records_on_page = Entry(subwindow, font=('Arial', 12))
        input_number_of_records_on_page.insert(0, '0')
        input_number_of_records_on_page.place(width=35, height=25, relx=0.32, rely=0.24)
        button_ok = Button(subwindow, text='ОК', font=('Arial', 12), command=lambda: self.controller.ok(self.search_model, subwindow,
                                                                             0.001, 0.3,  input_number_of_records_on_page))
        button_ok.place(width=35, relx=0.35, rely=0.24)

        label7 = Label(subwindow, text='Количество записей в таблице - ', font=('Arial', 12))
        label7.place(relx=0.6, rely=0.24)
        label_number_of_records = Label(subwindow, textvariable=self.search_model.number_of_records, font=('Arial', 12))
        label_number_of_records.place(relx=0.755, rely=0.24)

        button_first_page = Button(subwindow, text='1', font=('Arial', 12), command=lambda: self.controller.to_first_page(
                                                                                           self.search_model, subwindow,
                                                                                          0.001, 0.3,
                                                                                           input_number_of_records_on_page))
        button_first_page.place(width=25, relx=0.42, rely=0.24)
        button_prev_page = Button(subwindow, text='<', font=('Arial', 12), command=lambda: self.controller.to_prev_page(
                                                                                           self.search_model, subwindow,
                                                                                          0.001, 0.3,
                                                                                           input_number_of_records_on_page))
        button_prev_page.place(width=25, relx=0.45, rely=0.24)
        label8 = Label(subwindow, text='стр. ', font=('Arial', 12))
        label8.place(relx=0.48, rely=0.24)
        label_active_page = Label(subwindow, textvariable=self.search_model.active_page, font=('Arial', 12))
        label_active_page.place(relx=0.5, rely=0.24)
        button_next_page = Button(subwindow, text='>', font=('Arial', 12), command=lambda: self.controller.to_next_page(
                                                                                           self.search_model, subwindow,
                                                                                          0.001, 0.3,
                                                                                           input_number_of_records_on_page))
        button_next_page.place(width=25, relx=0.52, rely=0.24)
        button_last_page = Button(subwindow, textvariable=self.search_model.last_page, font=('Arial', 12),
                                                                                           command=lambda: self.controller.to_last_page(
                                                                                           self.search_model, subwindow,
                                                                                          0.001, 0.3,
                                                                                           input_number_of_records_on_page))
        button_last_page.place(width=35, relx=0.55, rely=0.24)

        button = Button(subwindow, text='НАЙТИ', font=('Arial', 20), command=lambda: self.controller.find_records(
                                                          self.search_model, self.main_model.records, subwindow,
                                                           input_number_of_records_on_page,
                                                    [input_name, [input_year, input_month, input_day],
                                                          input_sport, [input_winner, en1, en2, en3],
                                                          [input_prize1, input_prize2],
                                                          [input_winner_prize1, input_winner_prize2]]))
        button.place(relwidth=0.98, relheight=0.05, relx=0.01, rely=0.15)

    def delete_records_window(self):
        subwindow = Toplevel()
        subwindow.title('Удалений записей')
        subwindow.geometry('760x400+400+200')
        subwindow.resizable(False, False)
        subwindow.protocol('WM_DELETE_WINDOW', lambda: self.dismiss(subwindow))
        subwindow.grab_set()
        label1 = Label(subwindow, text='Введите название турнира: ', font=('Arial', 14))
        label1.place(relx=0.01, rely=0.0)
        input_name = Entry(subwindow, font=('Arial', 12))
        input_name.place(relwidth=0.55, relx=0.43, rely=0.0)

        label2 = Label(subwindow, text='Введите дату проведения турнира: ', font=('Arial', 14))
        label2.place(relx=0.01, rely=0.1)
        label_day = Label(subwindow, text='день:', font=('Arial', 14))
        label_day.place(relx=0.43, rely=0.1)
        input_day = ttk.Combobox(subwindow, values=[''] + [i for i in range(1, 32)], state='readonly', font=('Arial', 10))
        input_day.place(relwidth=0.06, relheight = 0.065, relx=0.5, rely=0.1)
        label_month = Label(subwindow, text='месяц:', font=('Arial', 14))
        label_month.place(relx=0.6, rely=0.1)
        input_month = ttk.Combobox(subwindow, values=[''] + [i for i in range(1, 13)], state='readonly', font=('Arial', 10))
        input_month.place(relwidth=0.06, relheight = 0.065, relx=0.69, rely=0.1)
        label_year = Label(subwindow, text='год:', font=('Arial', 14))
        label_year.place(relx=0.8, rely=0.1)
        input_year = ttk.Combobox(subwindow, values=[''] + [i for i in range(2000, 2026)], state='readonly', font=('Arial', 10))
        input_year.place(relwidth=0.08, relheight = 0.065, relx=0.86, rely=0.1)

        label3 = Label(subwindow, text='Выберите название вида спорта: ', font=('Arial', 14))
        label3.place(relx=0.01, rely=0.2)
        input_sport = ttk.Combobox(subwindow, values=self.main_model.sports, state='readonly')
        input_sport.place(relwidth=0.55, relx=0.43, rely=0.2)

        label4 = Label(subwindow, text='Введите ФИО победителя: ', font=('Arial', 14))
        label4.place(relx=0.01, rely=0.4)
        en1, en2, en3 = IntVar(), IntVar(), IntVar()
        check_button1 = Checkbutton(subwindow, text='фамилия', variable=en1, command=lambda: self.controller.change_entry_state(input_winner, en1, en2, en3))
        check_button1.place(relx=0.33, rely=0.3)
        check_button2 = Checkbutton(subwindow, text='имя', variable=en2, command=lambda: self.controller.change_entry_state(input_winner, en1, en2, en3))
        check_button2.place(relx=0.33, rely=0.4)
        check_button3 = Checkbutton(subwindow, text='отчество', variable=en3, command=lambda: self.controller.change_entry_state(input_winner, en1, en2, en3))
        check_button3.place(relx=0.33, rely=0.5)
        input_winner = Entry(subwindow, state='disabled', font=('Arial', 12))
        input_winner.place(relwidth=0.55, relx=0.43, rely=0.4)

        label5 = Label(subwindow, text='Введите размер призовых турнира: ', font=('Arial', 14))
        label5.place(relx=0.01, rely=0.6)
        label5_1 = Label(subwindow, text='нижний предел: ', font=('Arial', 14))
        label5_1.place(relx=0.43, rely=0.6)
        input_prize1 = Entry(subwindow, font=('Arial', 12))
        input_prize1.place(relwidth=0.2, relx=0.62, rely=0.6)
        label5_2 = Label(subwindow, text='верхний предел: ', font=('Arial', 14))
        label5_2.place(relx=0.7, rely=0.6)
        input_prize2 = Entry(subwindow, font=('Arial', 12))
        input_prize2.place(relwidth=0.08, relx=0.9, rely=0.6)

        label6 = Label(subwindow, text='Введите заработок победителя: ', font=('Arial', 14))
        label6.place(relx=0.01, rely=0.7)
        label6_1 = Label(subwindow, text='нижний предел: ', font=('Arial', 14))
        label6_1.place(relx=0.43, rely=0.7)
        input_winner_prize1 = Entry(subwindow, font=('Arial', 12))
        input_winner_prize1.place(relwidth=0.2, relx=0.62, rely=0.7)
        label6_2 = Label(subwindow, text='верхний предел: ', font=('Arial', 14))
        label6_2.place(relx=0.7, rely=0.7)
        input_winner_prize2 = Entry(subwindow, font=('Arial', 12))
        input_winner_prize2.place(relwidth=0.08, relx=0.9, rely=0.7)

        button = Button(subwindow, text='УДАЛИТЬ', font=('Arial', 20), command=lambda: self.controller.delete_records(
                                                          self.main_model, [input_name, [input_year, input_month, input_day],
                                                          input_sport, [input_winner, en1, en2, en3],
                                                          [input_prize1, input_prize2],
                                                          [input_winner_prize1, input_winner_prize2]]))
        button.place(relwidth=0.96, relheight=0.1, relx=0.02, rely=0.8)



