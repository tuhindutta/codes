// const http = require('http');
// const hostname = 'localhost';
const express = require("express");
const path = require("path");
const app = express();
const mongoose = require("mongoose");
// const bodyparser = require("body-parser");

// ref: https://mongoosejs.com/docs/
mongoose.connect('mongodb://localhost/test', {useNewUrlParser: true});
const port = 5000;

// Throwback connection success
const db = mongoose.connection;
db.on('error', console.error.bind(console, 'connection error:'));
db.once('open', function() {
  // we're connected!
});

// Define mongoose schema
const contactSchema = new mongoose.Schema({
    name: String
  });

// Prepare model
const Contact = mongoose.model('Contact', contactSchema);

// app.use(express.static('public', options)); //serving & intoducing static folder to express
app.use('/static', express.static(path.join(__dirname, 'public')))

app.set('view engine', 'pug'); //setting pug as template (view) engine
// app.set('views', path.join(__dirname, "views")); //joining vi/ews direc. for storing templates

app.get('/', function (req, res) {
    res.status(200).render('index')
});

app.get('/index.pug', function (req, res) {
    res.status(200).render('index')
});

// app.get("/", (req, res)=>{
//     res.send("This is my first express insatallation and publish")
// });

app.get('/contact', (req, res)=>{
    // const content = "This is a new line"
    // const newline = {"entry":content}
    // res.status(200).render('index', newline)
    res.status(200).render('contact')
});

app.get('/projects', (req, res)=>{
    res.status(200).render('projects')
});


app.post('/contact.pug', (req, res)=>{
    var myData = new Contact(req.body)
    myData.save().then(()=>{
        res.send("This item has been saved to the database")
    }).catch(()=>{
        res.status(404).send("This item has NOT been saved to the database")
    })
});

// Start the nodejs server
app.listen(port, /*hostname,*/ ()=>{
    console.log(`Hosting started at $(port)`)
});
