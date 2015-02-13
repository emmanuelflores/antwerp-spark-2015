<script type="text/javascript">
    function vidplay() {
	
       var video = document.getElementById("Video");
       var button = document.getElementById("play");
	   var deviceID    = "51ff6f065067545753240187"; //YOUR SPARK DEVICE ID
	   var accessToken = "4757c66fe986309b4e3a2f81b8f5f2e3423e94cb"; //YOUR SPARK ACCESS TOKEN
	   var getFunc = "button"; //THE NAME OF YOUR SPARK VARIABLE
	   
	   window.setInterval(function() { //THIS ALLOWS THE WEBSITE TO TALK TO THE SPARK CLOUD
	   requestURL = "https://api.spark.io/v1/devices/" + deviceID + "/" + getFunc + "/?access_token=" + accessToken;
	   
	   $.getJSON(requestURL, function(json) {  //THIS ASKS THE SPARKCLOUD FOR A VALUE
	   var button = json.result;           //THE SLIDER VALUE IS PULLED OUT OF THE SPARK CLOUD

	   if (video.paused) {
          video.play();
		  video.hidden = false;
          button.textContent = "||";
       } 
	   
	   else {
          video.pause();
		  video.hidden = true;
          button.textContent = ">";
       }
    }
    function restart() {
        var video = document.getElementById("Video");
        video.currentTime = 0;
    }
    function skip(value) {
        var video = document.getElementById("Video");
        video.currentTime += value;
    }     
</script>

</head>
<body>        

<video id="Video" >
     <source src="movie.mp4" type="video/mp4" />
</video>

<div id="buttonbar">
    <button id="restart" onclick="restart();">[]</button> 
    <button id="rew" onclick="skip(-10)">&lt;&lt;</button>
    <button id="play" onclick="vidplay()">&gt;</button>
    <button id="fastFwd" onclick="skip(10)">&gt;&gt;</button>
</div>