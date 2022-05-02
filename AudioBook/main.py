import pyttsx3
import PyPDF2

sach=open("SP.pdf", "rb")
pdfReader=PyPDF2.PdfFileReader(sach)
pages=pdfReader.numPages
print(pages)
bot=pyttsx3.init()
voices=bot.getProperty('voices')
bot.setProperty('voice', voices[0].id)
for num in range(8, pages):
    page=pdfReader.getPage(8)
    text=page.extractText()
    bot.say(text)
    bot.runAndWait()