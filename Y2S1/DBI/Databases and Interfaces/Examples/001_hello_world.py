# Specify that we want to "use" the flask module in
# our Python application
from flask import Flask

# This initializes the Flask instance to variable named app
# Note - we do not need to specify variable types in Python
# as it is dynamically typed
app = Flask(__name__)

# Specify the default route ("/" = Root directory) and associate
# it with the function "hello_world". 
@app.route('/')
def hello_world():
    # Not the importance of indentation in Python code.
    return 'Hello World!'

# This will serve as the entry point for our program. Here we 
# tell Flask to run and specify that we want output from the 
# debugger and specify the specific port we want to access the 
# service from. 

if __name__ == '__main__':
    app.debug = True
    # After this line executes, a long running Flask process will
    # "serve" our application, which will be accessible via:
    # http://localhost:5000 or http://127.0.0.1:5000 (on most systems)
    app.run(port=5000)
