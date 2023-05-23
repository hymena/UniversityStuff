var gl;
var numPoints = 5000;
var thetaLoc;
var theta;
var isDirClockwise = false;
var delay = 500;
window.onload = function main() {

	  const canvas = document.querySelector("#glcanvas");
	  // Initialize the GL context
	  gl = WebGLUtils.setupWebGL(canvas);
	  // Only continue if WebGL is available and working
	  if (!gl) {
	    alert("Unable to initialize WebGL. Your browser or machine may not support it.");
	    return;
	  }

	  	var program = initShaders(gl,"vertex-shader","fragment-shader");
		gl.useProgram( program );

		// adding button
		var myButton = document.getElementById("DirectionButton"); 
		myButton.addEventListener("click", function() {isDirClockwise = !isDirClockwise;});

		//changing speed
		document.getElementById("slide").onchange = function() {delay = this.value;};



		
		var vertices = [ vec2(-.5, -.5), 
		                 vec2(0.5, -.5),
		                 vec2(.5, .5),
		                 vec2(-.5, .5) ];




		var bufferId = gl.createBuffer();
		gl.bindBuffer( gl.ARRAY_BUFFER, bufferId );
		gl.bufferData( gl.ARRAY_BUFFER, flatten(vertices), gl.STATIC_DRAW );

		// Associate out shader variables with our data buffer
		var vPosition = gl.getAttribLocation( program, "vPosition" );
		gl.vertexAttribPointer( vPosition, 2, gl.FLOAT, false, 0, 0 );
		gl.enableVertexAttribArray( vPosition );

		thetaLoc = gl.getUniformLocation(program, "theta");
		theta=0;
		gl.uniform1f(thetaLoc, theta);

		render();

		

}

function render(){
	  // Set clear color to black, fully opaque
	  

	  setTimeout(function() {
	  	  requestAnimFrame(render);
		  gl.clearColor(0.0, 0.0, 0.0, 1.0);
		  gl.clear(gl.COLOR_BUFFER_BIT);
		  theta += (isDirClockwise ? -0.1 : 0.1);
	      gl.uniform1f(thetaLoc, theta);
		  gl.drawArrays(gl.TRIANGLE_FAN, 0, 4);
	}, delay);
	 


}