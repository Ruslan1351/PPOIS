from typing import List, Union

from Page import Page

def parse_number_of_pages(numbers: str, pages: List[Page]) -> List[Page]:
    if numbers == '' or numbers[-1] == ',' or numbers[0] == ',':
        print('Некорректный ввод!')
        return []
    numerals: List[str] = ['0', '1', '2', '3', '4', '5', '6', '7', '8', '9']
    parsed_numbers: List[int] = []
    i = 0
    while i < len(numbers):
        if numbers[i] not in numerals + ['-', ',']:
            print('Некорректный ввод(должны быть только цифры, запятые и дефисы)!')
            return []
        if i != len(numbers) - 1:
            if (numbers[i] == '-' and numbers[i + 1] == '-') or \
                    (numbers[i] == '-' and numbers[i + 1] == ',') or \
                    (numbers[i] == ',' and numbers[i + 1] == '-') or \
                    (numbers[i] == ',' and numbers[i + 1] == ','):
                print('Некорректный ввод!')
                return []
        i += 1
    parts: List[str] = numbers.split(',')
    for i in range(len(parts)):
        if '-' in parts[i]:
            if parts[i][0] == '-' or parts[i][-1] == '-' or parts[i][0] == '0':
                print('Некорректный ввод!')
                return []
            start, end = map(int, parts[i].split('-'))
            if start > end or end > len(pages):
                print('Некорректный ввод(неверный диапазон)!')
                return []
            for j in range(start, end + 1):
                if j in parsed_numbers:
                    print('Некорректный ввод(страницы не должны повторяться)!')
                    return []
                parsed_numbers.append(j)
        else:
            if parts[i][0] == '0':
                print('Некорректный ввод!')
                return []
            page_number: int = int(parts[i])
            if 1 <= page_number <= len(pages) and page_number not in parsed_numbers:
                parsed_numbers.append(page_number)
            else:
                print('Некорректный ввод!')
                return []
    parsed_numbers.sort()
    result: List[Page] = []
    for i in parsed_numbers:
        result.append(pages[i - 1])
    return result

def correct_input(correct_value: List[str], input_text: str) -> str:
    while True:
        input_value: str = input(input_text)
        if input_value not in correct_value:
            print('Некорректный ввод!')
        else:
            break
    return input_value

def handling_value_error(input_text: str, type_of_value: str) -> Union[int, float]:
    while True:
        try:
            if type_of_value == 'int':
                input_value: int = int(input(input_text))
            if type_of_value == 'float':
                input_value: float = float(input(input_text))
            return input_value
        except ValueError:
            print('Некорректный ввод')