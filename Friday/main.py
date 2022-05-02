import datetime
import speech_recognition as sr
import pyttsx3
import os
import webbrowser as wb

friday = pyttsx3.init()
voice = friday.getProperty('voices')
friday.setProperty('voice', voice[0].id)

def speak(audio):
    print('F.R.I.D.A.Y.: ' + audio)
    friday.say(audio)
    friday.runAndWait()

def time():
    Time = datetime.datetime.now().strftime("%I:%M:%p")
    speak(Time)

def welcome():
    hour = datetime.datetime.now().hour
    if 6 <= hour < 12:
        speak("Good Morning sir")
    elif 12 <= hour < 18:
        speak("Good Afternoon sir")
    if 18 <= hour < 21:
        speak("Good Night sir")
    speak("How can I help you?")

def command():
    c = sr.Recognizer()
    with sr.Microphone() as source:
        c.pause_threshold = 2
        audio = c.listen(source)
    try:
        query = c.recognize_google(audio, language = 'en')
        print("Tony Stark: " + query)
    except sr.UnknownValueError:
        print("Please repeat or typing the command!")
        query = str(input('Your order is: '))
    return query

if __name__ == "__main__":
    welcome()
    while True:
        query = command().lower()
        if "google" in query:
            speak("What should I looking for?")
            search = command().lower()
            url = f"https://www.google.com/search?q={search}"
            wb.get().open(url)
            speak(f"Here is your {search} on google")
        if "youtube" in query:
            speak("What should I looking for?")
            search = command().lower()
            url = f"https://www.youtube.com/search?q={search}"
            wb.get().open(url)
            speak(f"Here is your {search} on youtube")
        elif "open video" in query:
            print('WIP')
        elif "time" in query:
            time()
        elif "quit" in query:
            speak("F.R.I.D.A.Y. is quitting sir. Goodbye boss")
            quit()