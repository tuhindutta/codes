from django.shortcuts import render, HttpResponse

# Create your views here.
def index(request):
    context = {
        'variable':"this is set"
    }
    return render(request, 'index.html', context)