#!/usr/bin/env python3

from flask import Flask
app = Flask(__name__)

@app.route('/')
def hello_world():
	return 'Hello World!'

# We can specify additional routes
# This is an explicit route and will resolve only to "/hello" (not "/hello/")
@app.route('/hello')
def hello():
	return "Hello"

# Note - 
# If we define this route as /world, it will not match when we navigate to /world/.
# However, if we define this route as /world/, /world will be redirected to /world/.
# Then both URLS, with and without the trailing slash, map to this function.
@app.route('/world/')
def world():
	return "World"

# We can define variables within the URL, that are 
# then passed to the 
@app.route('/hello/<name>')
def hello_person(name):
	# We can specify our program's logic accordingly
	if name == "Dave":
		name = "Matt"
	return "Hello {}, welcome to DBI!".format(name)

if __name__ == '__main__':
	app.debug = True
	app.run(port=5000)
	