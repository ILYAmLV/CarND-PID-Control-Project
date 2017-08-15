# Self-Driving Car Engineer Nanodegree Program

## PID Control - Project 4

<p align="center">
    <img src="./imgs/pid.gif" width="600">
</p>

## Basic Build Instructions

1. Clone this repo.
2. Make a build directory: `mkdir build && cd build`
3. Compile: `cmake .. && make`
4. Run it: `./pid`. 


The goal of this project was to create a **`PID controller`** in `C++` to be used in a driving simulation. The simulator provided the **`Cross Track Error`** `(CTE)` and the **`Velocity`** `(mph)`. Our job was completing the PID class in `PID.cpp` and initializing the PID variable in `main.cpp`.

**`PID controller`** consists of three terms: 

* **`P`** - **`Proportional term`** produces an output that is proportional to the error value. My proportional term gain `Kp` is set to 0.105, having the gain set too high ends up causing oversteer as the controller provides too much output and overshoots the setpoint value. Having the gain set too low causes the car to drive off the track on sharp turns as the controller does not provide enough output to quickly react to a high error value.

* **`I`** - **`Integral term`** takes previous error values into consideration to predict the amount of output necessary to gradually approach the setpoint value. The integral term gain `Ki` is set to 0.0008, I have found the integral term to be moderately effective in preventing the car from swaying. Setting the gain any higher causes the car to overshoot the setpoint value and drive off the track.

* **`D`** - **`Derivative term`** makes the controller more stable by balancing out the proportional term's output. The derivative term gain `Kd` is set to 2.5, setting it lower causes the vehicle to steer too aggressively which is especially noticeable on a straight path with the car swaying side to side,  setting the gain higher takes care of the swaying problem but causes the controller to be less responsive and not providing enough output on sharp turns which causes the car to drive off the track.

To tune the controller I Used the 'trial and error' method - starting with the base parameters 1, 0, 0 and running the simulation, then changing the parameters and running the simulation again until I have reached the desired result - the car being able to make sharp turns at the highest speed possible, the lowest amount of swaying on a straight path. This is definitely the least efficient way of tuning a **`PID controller`** but it helped me get a better understanding of how the controller operates by manually setting the parameters and running the simulation I could see the effects of an algorithm on the car's behavior.

In addition to implementing a PID controller, I have also modified the throttle control:

```
		  if (fabs(cte) > 1.0 || // If too far RIGHT or
			  fabs(cte) < -1.0)  // too far LEFT
		  {
			  msgJson["throttle"] = -1.0; // Brake
		  }
		  else
		  {
			  msgJson["throttle"] = 1.0; // Otherwise full throttle
		  }
		  if (fabs(speed) < 50.0) // If speed less then 50
		  {
			  msgJson["throttle"] = 0.9; // 0.9 throttle
```
By combining the absolute value of `CTE` and throttle controls I was able to simplify the whole project. Whenever the car veered off too far left or too far right the controller would set the throttle to a negative value causing the car to brake and slow down, giving the car more time to restabilize and by adding the `(fabs(speed) < 50.0)` part I was able to prevent the car from loosing momentum or stopping completely. I have included a [Video](https://youtu.be/eQGfbPIb1_U) of the final result with the car going around the track twice and achieving the top speed of **98** `MPH`.
