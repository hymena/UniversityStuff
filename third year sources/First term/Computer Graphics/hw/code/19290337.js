let gl;
let thetaLoc;
var theta = 0;
var rotationSpeed = 0.0;
var translateX = 0;
var translateY = 0;
var translateXLoc;
var scale = 1;
var scaleLocation;
var translateYLoc;
var isDirClockwise = false;
var delay = 500;
var rgbLocation;
var rgb = [0.5,0.5,0.5,1];

function moveUp() {
	if (translateY < 1) {
		translateY += 0.1
		console.log(translateY);
	}
}
function moveDown() {
	if (translateY > -1) {
		translateY -= 0.1
	}
}
function moveRight() {
	if (translateX < 1) {
		translateX += 0.1
	}
}
function moveLeft() {
	if (translateX > -1) {
		translateX -= 0.1
	}
}
function toggleRotation() {
	rotationSpeed = rotationSpeed ? 0 : 0.1
}
function bigger() {
	if (scale < 2) {
		scale += 0.1
	}
}
function smaller() {
	if (scale > 0.3) {
		scale -= 0.1
	}
}
function randomColor() {
	for (var i = 0; i < 3; i++) {
		rgb[i] = Math.random()
		console.log(rgb[i]);
	}
}
function rotationDirection() {
	isDirClockwise = !isDirClockwise;
}

window.onload = function main() {

	const canvas = document.querySelector("#glcanvas");
	// Initialize the GL context
	gl = WebGLUtils.setupWebGL(canvas);
	// Only continue if WebGL is available and working
	if (!gl) {
		alert("Unable to initialize WebGL. Your browser or machine may not support it.");
		return;
	}

	var program = initShaders(gl, "vertex-shader", "fragment-shader");
	gl.useProgram(program);

	// adding buttons
	const myButton = document.getElementById("DirectionButton");
	myButton.addEventListener("click", rotationDirection);
	const moveToRightButton = document.getElementById("MoveToRight");
	moveToRightButton.addEventListener("click", moveRight)
	const moveToLeftButton = document.getElementById("MoveToLeft");
	moveToLeftButton.addEventListener("click", moveLeft)
	const moveToDownButton = document.getElementById("MoveToDown");
	moveToDownButton.addEventListener("click", moveDown)
	const moveToUpButton = document.getElementById("MoveToUp");
	moveToUpButton.addEventListener("click", moveUp)
	const stopRotationButton = document.getElementById("StopRotation");
	stopRotationButton.addEventListener("click", toggleRotation)
	const IncreaseSizeButton = document.getElementById("IncreaseSize");
	IncreaseSizeButton.addEventListener("click", bigger)
	const DecreaseSizeButton = document.getElementById("DecreaseSize");
	DecreaseSizeButton.addEventListener("click", smaller)
	const RandomColorButton = document.getElementById("RandomColor")
	RandomColorButton.addEventListener("click", randomColor)
	// Adding keyboard events 
	window.addEventListener("keydown",
		function () {
			switch (event.keyCode) {
				case 107: // ’+’ key
					bigger();
					break;
				case 109: // ’-’ key
					smaller();
					break;
				case 87: // ’w’ key
					moveUp();
					break;
				case 65: // ’a’ key
					moveLeft();
					break;
				case 68: // ’d’ key
					moveRight();
					break;
				case 83: // ’s’ key
					moveDown();
					break;
			}
		});
	//changing speed
	document.getElementById("slide").onchange = function () { delay = 1000-this.value; };
	document.getElementById("red").onchange = function () { rgb[0] = this.value; };
	document.getElementById("green").onchange = function () { rgb[1] = this.value; };
	document.getElementById("blue").onchange = function () { rgb[2] = this.value; };
	document.getElementById("opacity").onchange = function () { rgb[3] = this.value; };
	

	var vertices = [
		// The main part of the letter Ö
		vec2(-0.7, 0.4), vec2(-0.7, -0.4), vec2(-0.6, -0.4),
		vec2(-0.7, 0.4), vec2(-0.6, 0.4), vec2(-0.6, -0.4),
		vec2(-0.6, -0.4), vec2(-0.6, -0.3), vec2(-0.1, -0.3),
		vec2(-0.6, -0.4), vec2(-0.1, -0.3), vec2(-0.1, -0.4),
		vec2(-0.1, -0.4), vec2(-0.1, 0.4), vec2(0.0, 0.4),
		vec2(-0.1, -0.4), vec2(0.0, -0.4), vec2(0.0, 0.4),
		vec2(-0.6, 0.4), vec2(-0.6, 0.3), vec2(-0.1, 0.3),
		vec2(-0.6, 0.4), vec2(-0.1, 0.4), vec2(-0.1, 0.3),
		// The dots of the letter Ö
		vec2(-0.6, 0.5), vec2(-0.6, 0.6), vec2(-0.5, 0.5),
		vec2(-0.6, 0.6), vec2(-0.5, 0.6), vec2(-0.5, 0.5),
		vec2(-0.2, 0.5), vec2(-0.2, 0.6), vec2(-0.1, 0.6),
		vec2(-0.2, 0.5), vec2(-0.1, 0.5), vec2(-0.1, 0.6),
		// The letter L
		vec2(0.2, 0.4), vec2(0.3, 0.4), vec2(0.2, -0.4),
		vec2(0.3, 0.4), vec2(0.2, -0.4), vec2(0.3, -0.4),
		vec2(0.3, -0.4), vec2(0.3, -0.3), vec2(0.8, -0.3),
		vec2(0.3, -0.4), vec2(0.8, -0.3), vec2(0.8, -0.4),
	]
	var bufferId = gl.createBuffer();
	gl.bindBuffer(gl.ARRAY_BUFFER, bufferId);
	gl.bufferData(gl.ARRAY_BUFFER, flatten(vertices), gl.STATIC_DRAW);

	// Associate out shader variables with our data buffer
	var vPosition = gl.getAttribLocation(program, "vPosition");
	gl.vertexAttribPointer(vPosition, 2, gl.FLOAT, false, 0, 0);
	gl.enableVertexAttribArray(vPosition);
	translateXLoc = gl.getUniformLocation(program, "translateX")
	translateYLoc = gl.getUniformLocation(program, "translateY")
	thetaLoc = gl.getUniformLocation(program, "theta");
	scaleLocation = gl.getUniformLocation(program, "scaleFactor")
	rgbLocation = gl.getUniformLocation(program, "color")
	
	render();
}
function render() {
	// Set clear color to black, fully opaque
	setTimeout(function () {
		requestAnimFrame(render);
		gl.clearColor(0.0, 0.0, 0.0, 0.0);
		gl.clear(gl.COLOR_BUFFER_BIT);
		theta += (isDirClockwise ? -rotationSpeed : rotationSpeed);
		gl.uniform1f(thetaLoc, theta);
		gl.uniform1f(translateXLoc, translateX);
		gl.uniform1f(translateYLoc, translateY);
		gl.uniform4f(rgbLocation, rgb[0], rgb[1], rgb[2], rgb[3])
		gl.uniform1f(scaleLocation, scale);
		gl.drawArrays(gl.TRIANGLES, 0, 48);
	}, delay);
}