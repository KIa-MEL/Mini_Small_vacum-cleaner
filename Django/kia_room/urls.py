from django.urls import path
from . import views

urlpatterns = [
    path('on/' , views.on),
    path('off/' , views.off),
    path('status/' , views.status),
    path('' , views.index),
    
]

