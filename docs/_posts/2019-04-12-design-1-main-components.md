---
permalink: design-1-main-components/
title: Design 1 – Main Components
date: 2019-04-12
author: Andrew
layout: page
---

## Sketch

## Main Components

### Rails

I want to use standardised aluminium extrusion for the rails. These provide the main structure of the slider, and are also the guide surface along which the gantry slides. This is a good guide: [Beginner’s Guide to Building Things With V-Slot Aluminum Extrusion](https://www.makeuseof.com/tag/beginners-guide-building-things-v-slot-aluminum-extrusion/)

#### Choosing a profile
There are different kinds of profile. I can't find a comprehensive list anywhere, but there do seem to be some common types, and others may only differ from these in non-essential ways.

The two main profiles seems to be B-Type and I-Type (__Bosch Rexroth__ and __Item__ respectively). The B-type profile has a stepped slot, whereas the I-type has a smooth curve.

RS Components sell [RS-Pro branded extrusion](https://uk.rs-online.com/web/p/tubing-struts/8508476/). This has a 5 mm groove, and a 4.3 mm central hole. According to [this chart](https://www.boltdepot.com/fastener-information/metric-tap-drill-size.aspx) that can be tapped for a 5 mm thread.

They also have Bosch Rexroth branded extrusion with a 6 mm groove and a 5.5 mm central hole. Using that same table, that's a little off for tapping to a 6 mm thread, so I wonder if this is an imperial sizing?

There is also a newcomer to the field: V-type. From the [Beginner’s Guide to Building Things With V-Slot Aluminum Extrusion](https://www.makeuseof.com/tag/beginners-guide-building-things-v-slot-aluminum-extrusion/):

> T-Slot has a T-shaped groove on each side.
> V-Slot is similar, but it has a slight bevelled edge.
While this may seem like only a minor difference, it has a big impact in their use. V-Slot allows bearings and wheels to sit inside the profile, meaning it can also double as linear rail, greatly reducing the cost of parts for motion control.

> The two are somewhat interchangeable, but it’s usually best to stick with one type per project. Basic parts like brackets and T-Nuts work fine on either, however slightly more specialist parts — such as bearings or unusual joints — may only work on one or the other. Also, if you are mixing and matching parts, you may need to change or adapt your design, and have to purchase more lengths of one or the other extrusion.

> V-Slot was created by Mark Carew of OpenBuilds and is open source.


The V-type, as the name suggests, has a straight V-shaped bevel. I would say B-type or V-type would be best to take bearings depending on cost and availability (the latter is less of an issue if they can be easily swapped out for another type). V-slot accepts M5 bolts, so I think – at this stage – that V- and I-type profiles should be quite interchangeable.

#### Choosing size

I suspect two 2020 profile rails will be enough for this small span. 2040 mounted vertically would give me more rigidity. And the [8040 C Beam](https://ooznest.co.uk/product/c-beam-linear-rail-cut-to-size/) would be even more rigid:

![]({{site.baseurl}}/assets/C-Beam-Linear-Rail.jpg)

Ooznest has a [guide to help you estimate deflection](https://ooznest.co.uk/wp-content/uploads/2018/05/How-To-Estimate-Deflection.pdf).

In my case, the calculation looks like this:

![]({{site.baseurl}}/assets/deflection.png)

Let's plug in some numbers:

* Mass of the load: 1kg (roughly, for an SLR camera)
* F = Mass x Gravity = 1 * 9.81 = 9.81N
* L = 0.5m
* I (moment of inertia) = 6.988 * 10<sup>-9</sup> (for 2020 profile)
* E (modulus of elasticity) = 68.9 GPa (gigapascals) =  68.9 * 10<sup>9</sup> Pa

Therefore deflection  
= (9.81 * (0.5)<sup>3</sup>) / (48 * 68.9 * 10<sup>9</sup> * 6.988 * 10<sup>-9</sup>)  
= 1.22625 / 23110.7136  
= 0.000053 m  
= 0.053 mm  

So nothing to worry about at this length. However, if I made a 1 m long slider, deflection under ideal conditions for a 1 kg load would come out at: 9.81 / 23110.7136 = .00042 m = .42 mm. So for that span it might be worth using a more rigid profile.

For now, I'll go with 2020. However, there is one other advantage to a larger profile such as 2040. That has two holes at each end, allowing for more robust assembly. I'm concerned that the 2020, with only one hole at each end might twist in the assembly, causing the gantry to move poorly.



#### Choosing length

While a bigger slider is always more useful, a smaller one is cheaper, and easier to store, so I think a better target for a first build. If I decide to remake it, I can always disassemble the first version and re-use some parts for a bigger one.

**So – all other things being equal – I'll go for a 50 cm length.**

#### Prices

[2 x 50 cm 2020 V-Slot from Ooznest](https://ooznest.co.uk/product-category/parts/mechanical-parts/v-slot-extrusions/): £9.60 + postage

[2 x 50 cm 2020 IR Range Aluminium Profile (I-type) from KJN](): £7 + postage

[50 cm 8040 C-Beam from Ooznest](https://ooznest.co.uk/product/c-beam-linear-rail-cut-to-size/): £14.80 + postage (both ends tapped with 5mm holes: £16.24. I should be able to tap these myself if needed)

[1 m I-type from RS Components](https://uk.rs-online.com/web/p/tubing-struts/8508476/): £6.90 + postage


WIP: 2 x 40 cm 2040

### Motor

This project requires a stepper motor. For background on motors, see:
* [Motors – code, circuits, & construction](http://www.tigoe.com/pcomp/code/circuits/motors/)

On steppers specifically:
* [Stepper Motor Quickstart Guide - SparkFun Electronics](https://www.sparkfun.com/tutorials/400)
* [What is a Stepper Motor? -  Adafruit Learning System](https://learn.adafruit.com/all-about-stepper-motors)

Figuring out which size of motor is complicated, so instead, I went for the soft option, and asked some people who have worked with them, and looked at what other projects use. The consensus was to go for the NEMA 17. You might think NEMA is a brand name for a motor, but no, NEMA stands for [National Electrical Manufacturers Association](http://en.wikipedia.org/wiki/National_Electrical_Manufacturers_Association). The 17 refers to the size of the faceplate - 1.7" x 1.7".

According to <https://reprap.org/wiki/NEMA_Motor>
> Some (all?) NEMA 17 motors (is this specified in the standard?) have blind mounting holes 4.5 mm deep, tapped to accept M3x.50 metric bolts. The 4 mounting holes are in a square 31.0 mm (1.220 inch, about 7/32) center-to-center. The holes in the part that needs to be bolted to the NEMA 17 motor typically need to be reamed out with a 1/8" drill bit to allow the M3 bolt to pass through. The drive shaft is typically 5 mm dia.

According to <https://learn.adafruit.com/all-about-stepper-motors/types-of-steppers>:
>The NEMA numbers define standard faceplate dimensions for mounting the motor. They do not define the other characteristics of a motor. Two different NEMA 17 motors may have entirely different electrical or mechanical specifications and are not necessarily interchangeable.

Specs typically seem to vary on a number of common parameters:
*  Number of steps per full rotation: 200 (1.8&deg; steps) or 400 (0.9&deg; steps). For timelapse, I would assume a finer step gradation would be better.
* Current draw (i.e. power). These vary from about 0.3A to 2A. Some motor current are listed as 'per phase' so I don't know how comparable these are.
* Unipolar or bipolar – from [the Adafruit guide](https://learn.adafruit.com/all-about-stepper-motors/types-of-steppers):
  * Unipolar drivers, always energize the phases in the same way. One lead, the "common" lead, will always be negative. The other lead will always be positive. Unipolar drivers can be implemented with simple transistor circuitry. The disadvantage is that there is less available torque because only half of the coils can be energized at a time.")
  * Bipolar drivers use H-bridge circuitry to actually reverse the current flow through the phases. By energizing the phases with alternating the polarity, all the coils can be put to work turning the motor.
* 2-phase or 4-phase – from [the Adafruit guide](https://learn.adafruit.com/all-about-stepper-motors/types-of-steppers):
  * A two phase bipolar motor has 2 groups of coils. A 4 phase unipolar motor has 4. A 2-phase bipolar motor will have 4 wires - 2 for each phase. Some motors come with flexible wiring that allows you to run the motor as either bipolar or unipolar.

<!-- One question for me is: what is the speed range of each motor? I'm looking for wide range of traverse speeds, from say 50 cm in 50 minutes, to 50 cm in 5 seconds. Let's see what kinds of RP ranges that would cover

Don't think this is an issue, as for slow speeds, I can just move one step at a time, with delays between -->




Lets look at some actual motors for sale:

[**Ooznest**](https://ooznest.co.uk/product/nema17-stepper-motors/)
* Bipolar
* 2-phase
* 1.33A – 2A per phase (but note this motor is rated at 2.8V, not 12V like most others)
* 200 or 400 steps per rotation

Their cheapest motor is a 200 step 1.4A model for £9.90 (NEMA17 Stepper Motors - 1.8° - 1701HS140A - 21oz - 1.40A)

[**Cool Components**](https://coolcomponents.co.uk/products/stepper-motor-with-cable)

This is a Sparkfun model, for about £15:

* Step Angle (degrees) :1.8
* 2 Phase
* Rated Voltage : 12V
* Rated Current : 0.33A
* Holding Torque : 2.3kg*cm

[**Adafruit**](https://www.adafruit.com/product/324) seem to have something quite similar. ($14, 350 mA, 4-wire bipolar, 1.8° steps (200/revolution))

Digikey also has some pretty similar models: <https://www.digikey.co.uk/products/en/motors-solenoids-driver-boards-modules/stepper-motors/179?k=&pkeyword=&sv=0&pv14=126&sf=0&FV=ffe000b3&quantity=&ColumnSort=0&page=1&pageSize=25>

Adafruit specify the stepper above for their slider project, so this seems like a pretty good place to start.

### Motor driver

There are lots of different boards, based on different chips. So how do you choose?

From [How to Make a Robot - Lesson 5: Cho | RobotShop Community](https://www.robotshop.com/community/tutorials/show/how-to-make-a-robot-lesson-5-choosing-a-motor-controller)

> 1 Is the motor you selected unipolar or bipolar? Choose a stepper motor controller type accordingly, though a growing number are able to control both types. The number of leads is usually a dead give-away of the motor type: if the motor has 4 leads, then it is bipolar; should it have 6 or more leads, then it is unipolar.
> 2 Choose the motor controller voltage range to match your motor’s  nominal voltage .
> 3 Find out how much current per coil your motor requires, and find out how much current (per coil) the stepper motor controller can provide.If you cannot find the current per coil, most manufacturers list the coil impedance, R . Using Ohms Law (V=IR), you can then calculate the current (I).
> 4 As with DC motor controllers, the control method is an important consideration.

From [Stepper Motor Control - Adafruit Motor Selection Guide](https://learn.adafruit.com/adafruit-motor-selection-guide/stepper-motor-control):

> Stepper motor controllers are more complex than DC motor controllers. Driving a bipolar motor with microstepping requires 2 complete H-bridges and 2 channels of PWM.
>
> The versatile Adafruit Motor Shield V2 has 4 H-bridges and can drive as many as 2 steppers. What’s more, it is stackable to control dozens of motors.

From [Driving a Stepper - All About Stepper Motors - Adafruit](https://learn.adafruit.com/all-about-stepper-motors/driving-a-stepper#simple-dual-h-bridge-driver-3-8):

> Simple Dual H-Bridge Driver
> Driving a bipolar motor requires 2 full H-bridges so it can reverse the current to the phases. H-bridges can be tricky to build from scratch. But there are plenty of H-bridge chips available to simplify the task.>
> The L293D is one of the most popular and economical chips. These can be found at the heart of most first-generation motor shields, including the incredibly popular V1 Adafruit Motor Shield.


The motors I'm looking at are bipolar, with 4 leads, and run at 12 V and 0.33/0.35 A.

It looks like an [Allegro 3967](https://cdn.sparkfun.com/datasheets/Robotics/A3967-Datasheet.pdf)-based driver board should work. This chip is rated to ±750 mA, 30 V

* This is the basis of the Sparkfun [Easy Driver](https://www.sparkfun.com/products/12779) ($15)
* SeeedStudio also have a similar board: [Stepper Motor Driver V4.5](https://www.robotshop.com/en/seeedstudio-stepper-motor-driver-v45.html) ($13)

This board design is open source ([documented here](https://www.schmalzhaus.com/EasyDriver/)), so I could, for version 2, fab my own using this chip. Perhaps with an integrated microcontroller. It also means there are numerous cheaper knock-offs available:
* [EasyDriver Stepper Motor Controller A3967](https://www.robotshop.com/uk/easydriver-stepper-motor-controller-a3967.html?gclid=CjwKCAjwkcblBRB_EiwAFmfyy-HjeUl_Ap48ECwBfiyV5jDxnGe6g75EDma3Y4imePHr335mSF3lBxoCsGcQAvD_BwE) (£5.70)
* [This on Amazon](https://www.amazon.co.uk/Aihasd-EasyDriver-Stepper-Development-Arduino/dp/B00WR8IQHW) (£2.80)
* [This on eBay](https://www.ebay.co.uk/p/EasyDriver-Shield-Stepping-Stepper-Motor-Driver-V44-A3967-for-Arduino/2169027753?iid=181921201075&chn=ps) (£1.30)


There is another Allegro chip, the [A4988](https://cdn.sparkfun.com/datasheets/Robotics/A4988-Datasheet.pdf), which is rated to 35 V and ±2 A.

* This is used in Sparkfun's [Big Easy Driver](https://www.sparkfun.com/products/12859) ($20)
* Pololu also have a much cheaper board: [A4988 Stepper Motor Driver Carrier](https://www.pololu.com/product/1182) $6

Adafruit have a nice board, the [Motor/Stepper/Servo Shield for Arduino v2 Kit - v2.3](https://www.adafruit.com/product/1438), based on the TB6612, which can drive up to two steppers at 1.2 A per channel. This is $20, so comparable to other brand-name boards that can only drive one stepper.

There are many others, including the [STMicroelectronics L293D](http://www.st.com/st-web-ui/static/active/en/resource/technical/document/datasheet/CD00000059.pdf) used in the [Adafruit Arduino Motor Shield](http://www.adafruit.com/index.php?main_page=product_info&products_id=81) and [Toshiba TB6600](http://www.semicon.toshiba.com.cn/info/docget.jsp?type=Catalog1&lang=en&pid=TB6600HG) used in the [PiBot TB6600 Stepper Driver](http://reprap.org/wiki/PiBot_TB6600_Stepper_Driver) and also in the _fab-able_ [satstep6600](https://github.com/satstep/satstep6600).

[Reprap also has a good list of different driver chips.](https://reprap.org/wiki/Stepper_motor_driver)

I think a 3967-based driver is enough for me to start with, and keeps costs down.

### Microcontroller

Although I'm interested in making an integrated board that incorporates an AVR microcontroller and one or more stepper drivers, it's also a valid choice to design around a microcontroller that people already have.

For the Easy Driver-style boards, hookup varies depending on whether you want to control the microstep resolution with the Arduino (which requires 3 more pins).

The [simplest hookup](http://www.schmalzhaus.com/EasyDriver/Examples/EasyDriverExamples.html) just uses 2 pins to control step and direction, with power coming from a separate supply:
![]({{site.baseurl}}/assets/Example1_bb.png)

There is also an example given for multiple steppers, for which you need to use a library:
![]({{site.baseurl}}/assets/Example4_bb.png)

Again, this just uses 2 pins per motor. If I want to use two steppers, and also use all the control pins on the drivers, this may cause problems down the line...

The [Adafruit board](https://www.adafruit.com/product/1438) uses I2C, making it very easy to control multiple motors:
> Instead of using a latch and the Arduino's PWM pins, we have a fully-dedicated PWM driver chip onboard. This chip handles all the motor and speed controls over I2C. Only two data pins (SDA & SCL in addition to the power pins GND & 5V) are required to drive the multiple motors, and since it's I2C you can also connect any other I2C devices or shields to the same pins. This also makes it drop-in compatible with any Arduino, such as the Uno, Due, Leonardo and Mega R3.



### Power supply

From [Stepper Motor Quickstart Guide - SparkFun Electronics](https://www.sparkfun.com/tutorials/400):
>  Stepper motors require more power than can be supplied by the Arduino. In this example we will be powering the Uno with a 12V external supply. Notice that the power input (M+) on the EasyDriver is attached to the Vin pin on the Arduino. This will allow you to power both the Arduino and the motor with the same power supply.

From https://learn.adafruit.com/motorized-camera-slider-mk3?view=all#12v-power-14-1
> 12V Power
> To properly power the stepper motor, you need at least 12V. A USB battery pack typically is only 5V and will not provide enough juice to push the weight of a camera (be it a lightweight GoPro or Mobile Phone). I highly suggest using either a 12V power wall adapter or 12V battery pack.
> Wall Adapter
> I mostly use the camera slider indoors. Having it plugged into the wall is nice because I don't have to worry about batteries getting low and dying. This  [12V DC 1000mA power adapter](https://www.adafruit.com/product/798)  works great with this project.
> PortabilityIf you plan to use the slider outdoors, I suggest using an  [8 x AA battery power pack](https://www.adafruit.com/product/875) . This features an on/off switch and 2.1mm barrel jack that plugs directly into the Adafruit Metro.


### Gantry

Different sized bolts for camera mounts


### Wheels/bearings



### Belt


### Pulleys


### End caps / feet


### Assembly brackets

### Fixings

It wold be nice if the design could standardise on one bolt size, say M5, with one head type. For example, if all bolts had Allen key heads of the same size, you could include the correct key somewhere on the frame of the machine, for easy adjustment or tightening.
