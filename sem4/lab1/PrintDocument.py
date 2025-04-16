from typing import List

from Page import Page

class PrintDocument:
    def __init__(self, type: str, name: str, pages: List[Page]) -> None:
        self.type = type
        self.name = name
        self.pages = pages
