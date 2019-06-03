const randomButton = document.querySelector('.random');

//random dog image
//click and change
randomButton.addEventListener('click', getRandomDoggo);

function getRandomDoggo(){
	console.log("get random doggo");
  fetch('https://dog.ceo/api/breeds/image/random')
    .then(checkStatus)
    .then(response => response.json())
    .then(data => handleData(data))
    .catch(error => notifyUser(error))
}

function startTimer(duration, display) {
    var timer = duration, minutes, seconds;
    setInterval(function () {
        minutes = parseInt(timer / 60, 10);
        seconds = parseInt(timer % 60, 10);

        minutes = minutes < 10 ? "0" + minutes : minutes;
        seconds = seconds < 10 ? "0" + seconds : seconds;

        display.textContent = minutes + ":" + seconds;

        if (--timer < 0) {
            timer = duration;
        }
    }, 1000);
}

window.onload = function () {

    var twentyFiveMinutes = 60 * 25,
        display = document.querySelector('#time');
    startTimer(twentyFiveMinutes, display);
};