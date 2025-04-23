import xml.sax

class RecordsHandler(xml.sax.ContentHandler):
    def __init__(self):
        self.records = []
        self.current_record = {}
        self.current_element = ""

    def startElement(self, name, attrs):
        self.current_element = name
        if name == "record":
            self.current_record = {}

    def characters(self, content):
        if self.current_element and content.strip():
            self.current_record[self.current_element] = content.strip()

    def endElement(self, name):
        if name == "record":
            self.records.append(self.current_record)
        self.current_element = ""