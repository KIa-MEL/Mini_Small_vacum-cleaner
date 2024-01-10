from django.urls import path
from . import views

urlpatterns = [
    path('<str:hc05_str>/hc05/' , views.hc05),
    path('off/' , views.off),
    path('hc05_status/' , views.hc05_status),
    path('' , views.index),
    
]

