from django.db import models

# Create your models here.
class LED(models.Model):
    status = models.CharField(max_length=10)