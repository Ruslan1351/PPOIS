class Paper:
    def __init__(self, format: str) -> None:
        self.format = format

    def __eq__(self, other: object) -> bool:
        if isinstance(other, Paper):
            return self.format == other.format
        return False