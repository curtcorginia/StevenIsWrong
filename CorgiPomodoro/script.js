//Heavily taken from open source codepen submission by Kostas https://codepen.io/kkoutoup/pen/wjZXPw

const randomButton = document.querySelector('.random');

//random dog image
//click and change
//randomButton.addEventListener('click', getRandomCorgi);
getRandomCorgi();

function getRandomCorgi(){
	console.log("Random corgi of the day");
  fetch('https://dog.ceo/api/breed/Pembroke/images/random')
    .then(checkStatus)
    .then(response => response.json())
    .then(data => handleData(data))
    .catch(error => notifyUser(error))
}



//handleData
function handleData(data){
  let url = data.message;
  console.log(url)
  let regex = /https:\/\/images\.dog\.ceo\/breeds\/(\w+\-?\w+)\/.+/g;
  //let breedName = regex.exec(url);
  let breedName = 'corgi';
  //document.getElementById('randomImageContainer').innerHTML = `<img alt="random image of a ${fixBreed(breedName[1])}" src='${url}'/>`;
  //document.querySelector('.dogInfo').innerHTML = `<p class="h5">Random image of a ${fixBreed(breedName[1])}</p>`;

  document.getElementById('randomImageContainer').innerHTML = `<img alt="random image of a corgi" src='${url}'/>`;
  document.querySelector('.dogInfo').innerHTML = `<p class="h5">Random image of a corgi</p>`;
}

//fixBreed
function fixBreed(breedName){
  
  /*
  if(breedName === 'germanshepherd'){
    return 'German Shepherd';
  }else if(breedName === 'mexicanhairless'){
    return 'Mexican Hairless';
  }else if(breedName === 'stbernard'){
    return 'St. Bernard';
  }else if(breedName === "african"){
    return 'African Wild Dog';
  }else if(breedName === 'bullterrier'){
    return 'Bull Terier';
  }

  */
  breedName === 'corgi';
  return capitalize(breedName);
}

//capitalize breed name
function capitalize(breedName){
  return breedName.replace(/\-/g,' ')
                  .split(" ")
                  .map(word => word.charAt(0).toUpperCase()+word.slice(1))
				          .join(" ");
}

//HELPER FUNCTIONS
//checkStatus
function checkStatus(response){
  if(response.ok){
    return Promise.resolve(response);
  }else{
    return Promise.reject(new Error(response.statusText));
  }
}

function notifyUser(error){
  const errorContainer = document.querySelector('.alert');
  errorContainer.innerHTML = `There was an error with the server request (${error}). <br> Click the button again.`;
  errorContainer.style.display = 'block';
  setTimeout(()=>{
    errorContainer.innerHTML = '';
    errorContainer.style.display ='none';
  },4000)
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
        	var audio = new Audio('Dog Woof-SoundBible.com.mp3');
audio.play();
        	
            timer = duration;
        }
    }, 1000);
}

window.onload = function () {

    var twentyFiveMinutes = 60 * 1,
        display = document.querySelector('#time');
    startTimer(twentyFiveMinutes, display);
};