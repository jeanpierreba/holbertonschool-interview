#!/usr/bin/node
// Prints all characters of a specific movie of star wars
const request = require('request');
request(`https://swapi-api.hbtn.io/api/films/${process.argv[2]}`, (error, response, body) => {
  if (!error) {
    const character = JSON.parse(body).characters;
    requestPrint(character, 0);
  }
});

function requestPrint (url, n) {
  request(url[n], (error, response, body) => {
    if (!error) {
      console.log(JSON.parse(body).name);
      if (n + 1 < url.length) requestPrint(url, ++n);
    }
  });
}
