# Yi DING 20320370
import sqlite3
from flask import (Flask, render_template, url_for, redirect,request)

app=Flask(__name__)
@app.route('/hello')
def hello_world():
	return 'Hello World!'

# @app.route('/hello/<name>')
# def hello_person(name):
# 	return "Hello {}!".format(name)

@app.route('/hello/<name>')
def hello_person(name):
    # Strip - Removes and preceding and trailing whitespace 
    # from a string
    # Capitalize - capitalizes the first character
    lname = name.strip().capitalize();
    return render_template("hello.html", name=lname)

@app.route('/people/')
def get_people_info():
    
    # Establish a connection with our Student DB file
    conn = sqlite3.connect('People.db')    
    # Converts the plain tuple result into a more useful object.
    conn.row_factory = sqlite3.Row
    # sqlite3.Cursor allows us to execute SQLite statements, fetch data 
    # from the result sets of the queries.
    cur = conn.cursor()
    # Here we say - execute this SQL query 
    cur.execute("SELECT * FROM People;")
    # Fetch all the results from the above query. 
    # We may alternatively request a single - fetchone
    rows = cur.fetchall();
    
    return render_template("people.html",rows = rows)

@app.route('/people/add/')
def add():
    return render_template("add.html")

@app.route('/add_people_to_db/', methods = ['POST'])
def add_people_to_db():
    
    # Should always be true, as we specified the Method above
    if request.method == 'POST':
        name = request.form['name']
        age = request.form['age']
    
    # Using "with" will automatically close the connection to the
    # sqlite DB after the inner block completes
    with sqlite3.connect("People.db") as conn:
        # Uncomment the below statement to enable autocommits
        # conn.isolation_level = None
        try:
            cur = conn.cursor()
            cur.execute("INSERT INTO People (pName,sAge) VALUES (?,?)", (name,age) )
            # IMPORTANT - Commit your changes, or they (may) be lost
            conn.commit()
        except sqlite3.Error as er:
            print("There was an error adding a new people to the DB!")
            print(er)
            return redirect(url_for('add'))
    return redirect(url_for('get_people_info'))



if __name__=='__main__':
	app.debug= True
	app.run(port=5000)
