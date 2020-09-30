var connect = require('connect');
var logger = require("morgan"); 
var serve_static = require("serve-static"); 
var http = require('http');
var ejs = require('ejs');
var bodyparse = require('body-parser');
var cookieparser = require('cookie-parser');
var ex_session = require('express-session');
var MongoClient = require('mongodb').MongoClient;
var address = 'mongodb://localhost:27017/test';

MongoClient.connect(address, function (err, db) {
    if(err == null) {
        console.log("Connected correctly to server.");
    }
});

var app = connect()
    .use (logger('dev'))
    .use (cookieparser())
    .use (ex_session( { secret : 'cmps369'}))
    .use (bodyparse())
    .use (serve_static('public'))
    .use (serve);

http.createServer(app).listen(3000);

var ContactList = new Array;
var Contact = new Object();

function serve (req, res) {
    console.log(req.url);
    if ( req.url == "/Form") {
        console.log("Receiving contact...");
        render (res, "Form", {});
    }
    else if ( req.url == "/Info") {
        var c = new Contact;
        c['Prefix'] = req.body.Prefix;
        c['FirstName'] = req.body.FirstName;
        c['LastName'] = req.body.LastName;
        c['Street'] = req.body.Street;
        c['City'] = req.body.City;
        c['State'] = req.body.State;
        c['Zip'] = req.body.Zip;
        c['Phone'] = req.body.Phone;
        c['Email'] = req.body.Email;
        c['Contact1'] = req.body.Contact1;
        c['Contact2'] = req.body.Contact2;
        c['Contact3'] = req.body.Contact3;
        c['Contact4'] = req.body.Contact4;
        
        ContactList.push(c);
        console.log("Contact received.")
        render (res, "Info", {contact:c});
    }
    else if ( req.url == "/Contacts") {
        console.log("Displaying contacts.");
        render (res, "Contacts", {contacts:ContactList});
    }
    else {
        console.log(err);
        res.end("Page not found!");
    }
}

function render (res, view, model) {
     ejs.renderFile("templates/" + view + ".ejs" ,model,
        function(err, result) {
            if (!err) {
                res.end(result);
            }
            else {
                console.log(err);
                res.end("An error occurred");
            }
        }
    );
}