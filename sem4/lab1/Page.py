class Page:
    def __init__(self, content: str) -> None:
        self.content = content

    def __eq__(self, other: object) -> bool:
        if isinstance(other, Page):
            return self.content == other.content
        return False