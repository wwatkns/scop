# scop

_This project is an introduction to OpenGL in order to display a 3D object parsed manually from a .obj file._
_We must display the model in perspective and with a simple texture mapping technique._

__Installation:__

* `git clone https://github.com/wwatkins42/scop.git`
* `cd ./scop`
* `make`

__Usage:__
* `./scop [.obj filename]`

__Example:__
* `./scop ./resources/teapot2.obj`

__Keys:__

* `w` `a` `s` `d` `shift` `ctrl`: Move camera.
* `i` `j` `k` `l` `pgup` `pgdwn`: Move model.
* `1`: Wireframe modifier.
* `2`: Shading modifier.
* `3`: Greyscale modifier.
* `4`: Texture projection modifier.
* `t`: Texture on/off.
* `c`: Change color.
* `r`: Camera anchor.
* `=` `-`: Augment/reduce model rotation speed.
* `keyboard` `+` `-`: Augment/reduce camera fov.

![Deer](https://raw.githubusercontent.com/wwatkins42/scop/master/resources/screenshots/Screen%20Shot%202016-12-12%20at%202.10.50%20PM.png)
![teapot smooth shading](https://raw.githubusercontent.com/wwatkins42/scop/b4b4cb1d5025bd91d24212574aec1c8c263d9420/resources/screenshots/Screen%20Shot%202016-12-12%20at%2010.34.57%20AM.png)
![teapot wireframe](https://raw.githubusercontent.com/wwatkins42/scop/b4b4cb1d5025bd91d24212574aec1c8c263d9420/resources/screenshots/Screen%20Shot%202016-12-12%20at%2010.35.35%20AM.png)
![42 color](https://raw.githubusercontent.com/wwatkins42/scop/b4b4cb1d5025bd91d24212574aec1c8c263d9420/resources/screenshots/Screen%20Shot%202016-12-12%20at%2010.36.13%20AM.png)
