from django.shortcuts import render
from django.http import HttpResponse
from django.core.files.base import ContentFile
from django.core.files.storage import default_storage


def hc05(request , hc05_str):
    file = default_storage.open('/hc05_status.txt' , 'wb')
    file.write(hc05_str)
    file.close()
    return render(request, 'tempreture.html')
    
def off(request):
    file = default_storage.open('/status.txt' , 'wb')
    file.write('off')
    file.close()
    return render(request, 'off.html')

def hc05_status(request):
    file = default_storage.open('/hc05_status.txt' , 'rb')
    return HttpResponse(file.read())

def index(request):
    return render(request, 'index.html')