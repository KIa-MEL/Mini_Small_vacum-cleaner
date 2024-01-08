from django.shortcuts import render
from django.http import HttpResponse
from django.core.files.base import ContentFile
from django.core.files.storage import default_storage


def on(request):
    file = default_storage.open('/status.txt' , 'wb')
    file.write('on')
    file.close()
    return render(request, 'on.html')

def off(request):
    file = default_storage.open('/status.txt' , 'wb')
    file.write('off')
    file.close()
    return render(request, 'off.html')

def status(request):
    file = default_storage.open('/status.txt' , 'rb')
    return HttpResponse(file.read())

def index(request):
    return render(request, 'index.html')