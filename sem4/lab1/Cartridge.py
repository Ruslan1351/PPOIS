from Ink import Ink

class Cartridge:
    def __init__(self, ink: Ink, volume: float) -> None:
        self.ink = ink
        self.volume = volume
        self.ink_text_consumption: float = 0.03
        self.ink_image_consumption: float = 0.08
        self.ink_filling: int = 1

    def fill_ink(self, volume: float) -> None:
        self.ink.volume += volume
        if volume >= self.volume / 2:
            self.ink_filling += 1

    def change_ink(self, new_ink: Ink) -> None:
        self.ink = new_ink
        self.ink_filling += 1