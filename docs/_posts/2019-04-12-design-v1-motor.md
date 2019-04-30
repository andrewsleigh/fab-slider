---
permalink: design-v1-motor/
title: Designing version 1 – Choosing a motor
date: 2019-04-12
author: Andrew
layout: page
sort_id: 32
---



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

[Digikey also has some pretty similar models](https://www.digikey.co.uk/products/en/motors-solenoids-driver-boards-modules/stepper-motors/179?k=&pkeyword=&sv=0&pv14=126&sf=0&FV=ffe000b3&quantity=&ColumnSort=0&page=1&pageSize=25)

Adafruit specify the stepper above for their slider project, so this seems like a pretty good place to start.

### Motor driver

There are lots of different boards, based on different chips. So how do you choose?

From [How to Make a Robot - Lesson 5: Cho - RobotShop Community](https://www.robotshop.com/community/tutorials/show/how-to-make-a-robot-lesson-5-choosing-a-motor-controller)

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

Either way, for now, I should be able to get away with a standard Arduino Uno, and may be able to specify a smaller board like the Pro Mini, or maybe, for version 2, an ATtiny-based DIY board if I need only a few pins.



### Power supply

From [Stepper Motor Quickstart Guide - SparkFun Electronics](https://www.sparkfun.com/tutorials/400):
>  Stepper motors require more power than can be supplied by the Arduino. In this example we will be powering the Uno with a 12V external supply. Notice that the power input (M+) on the EasyDriver is attached to the Vin pin on the Arduino. This will allow you to power both the Arduino and the motor with the same power supply.

From https://learn.adafruit.com/motorized-camera-slider-mk3?view=all#12v-power-14-1
> 12V Power
> To properly power the stepper motor, you need at least 12V. A USB battery pack typically is only 5V and will not provide enough juice to push the weight of a camera (be it a lightweight GoPro or Mobile Phone). I highly suggest using either a 12V power wall adapter or 12V battery pack.
> Wall Adapter
> I mostly use the camera slider indoors. Having it plugged into the wall is nice because I don't have to worry about batteries getting low and dying. This  [12V DC 1000mA power adapter](https://www.adafruit.com/product/798)  works great with this project.

The Arduino Uno has a barrel jack power input, and can pass through 12V power to the driver board, so I think this is the best way to go. I have several old 12V wall-warts that can supply 1 or 2 A of current.

For portable power, an [8 x AA battery power pack](https://www.adafruit.com/product/875) is probably the best option.

### Gantry

The gantry is basically just a flat plate with mounting holes for attaching different devices, and for the wheels and timing belt.

Ooznest sell an [aluminium gantry plate](https://ooznest.co.uk/product/c-beam-gantry-plate-kit/)for the 8040 V-slot C-beam (in a kit form with delrin wheels for £25). This C-beam has a 40 mm channel down the middle, so it should be adaptable for two lengths of 2020 mounted 40 mm apart.

![]({{site.baseurl}}/assets/C-Beam-Gantry-Plate-Kit.jpg)

They also have a [simpler plate](https://ooznest.co.uk/product/v-slot-gantry-plate-small-kit/) designed to straddle a single 2020 rail. (£24 in a kit with 4 wheels).

![]({{site.baseurl}}/assets/V-Slot-Gantry-Plate-Kit-Small-3.jpg)

These are really nice plates, and you could certainly make something similar out of laser-cut acrylic.


#### Mounting a camera

Camera mounts are standardised around a 1/4" screw. Even mounts for phones typically have a 1/4" threaded hole so thy can be mounted on standard camera accessories, like tripods. So this is a good fitting onto which I could fit any number of off-the-shelf mounting parts, such as this [camera mount](https://www.adafruit.com/product/2464).

An aluminium baseplate could have a threaded hole to accept a 1/4" bolt. I can't create a threaded hole in an acrylic baseplate but I could create a two-layer plate, where the top layer has a hexagonal hole to capture a nut into which a bolt could be threaded.

Note: the camera needs to be able to site flush against the top face of the gantry. So any other fixings – for example the timing belt, or the bolts for the wheels – need to be recessed or otherwise out of the way. With a metal (or wooden) plate, this is easy enough, you could use countersink-headed bolts. But you can't laser-cut acrylic with countersink holes, so again, I'm leaning towards a 2-layer design. 3D printing would be another option.

#### Attaching the timing belt

The Adafruit slider uses a vertical drive shaft, meaning that the timing belt is also vertical. They use a nice kinked channel in the gantry plate to hold the (continuous loop of belt) belt in place.

![]({{site.baseurl}}/assets/3d_printing_belt-tensioner-1.jpg)

This picture also shows the use of a belt tightener.

The Ooznest design uses a drive shaft in a horizontal orientation, so the belt is transposed through 90&deg;. You can see the slots on the edges of the gantry plate through which you could thread each end of the timing belt, to be secured with a cable grip.

![]({{site.baseurl}}/assets/gantry-belt.png)

This approach allows you to cut the belt to whatever size works. I think this is a better approach for me, assuming I use a laser-cut gantry.

#### Mounting bearings

This image of the Ooznest gantry show the kind of method I'd like to use. As they use an aluminium plate, they're able to cut recessed holes for the bolt heads to allow them to sit flush with the top surface. I think I could achieve the same effect with a 2-layer laser-cut acrylic plate. Or by conventional manual countersinking in a MDF laser-cut plate.

![]({{site.baseurl}}/assets/Mini-V-Gantry-Plate-Kit-6.jpg)

Some kits (e..g the Ooznest kit) use eccentric spacers to allow the wheels to be adjusted in fine increments. A simpler – and perhaps adequate – solution would be to use slots rather than round holes to accept the wheel bolts.

### Wheels/bearings

I'm looking to mount 4 wheels on bearings in a horizontal orientation underneath my gantry.
It's possible I can[ 3D-print the wheels](https://www.thingiverse.com/thing:1452180) themselves, but I'd still need the bearing, bolt and spacer assembly.
So I'm inclined, for version one, to buy the complete assembly, and see if I can swap out some commercial parts for DIY versions later. Apart from anything, I'd like to see what difference it makes to the motion of the gantry. But wheel kits are expensive:

* [Ooznest Delrin Dual V Wheel](https://ooznest.co.uk/product/delrin-dual-v-wheel/), including M5 bolt and 6mm spacer: £4.44 each
* [Ooznest Mini V Wheel Wheel](https://ooznest.co.uk/product/mini-v-wheel/), including M5 bolt and 6mm spacer: £3.44 each

Alternatively, cheaper versions are available on Amazon, etc. For example, [BIQU Equipment Wheel with Bearings (Pack of 5)](https://www.amazon.co.uk/BIQU-Printer-Plastic-Bearings-Passive/dp/B06X9Q9Y8V/ref=sr_1_4?keywords=v+slot+wheels&qid=1555184059&s=industrial&sr=1-4) (£6)
 or [Samje Wheels (Pack of 5)](https://www.amazon.co.uk/Samje-Printer-Plastic-Bearings-Passive/dp/B07F61MXGR/ref=pd_vtph_tr_t_2/261-5809806-6631247?_encoding=UTF8&pd_rd_i=B07F61MXGR&pd_rd_r=28f8c8aa-5e23-11e9-bed5-07a155c29bc6&pd_rd_w=J1Icp&pd_rd_wg=N4Yzl&pf_rd_p=eb02db1b-a172-4b0e-887c-299e5e502bb0&pf_rd_r=TGDH5HTKWQHMF731M2QV&refRID=TGDH5HTKWQHMF731M2QV&th=1) (£9)



### Belt

GT2 Belt seems to be pretty standard. That means it has a pitch of 2 mm between the teeth. The 6 mm wide belt seems to be the most common.

* [Ooznest](https://ooznest.co.uk/product/gt2-open-timing-belt-per-metre/): £2.90/metre
* [Adafruit](https://www.adafruit.com/product/1184): $10 / 1164mm long (continuous loop)



### Pulleys and/or bearings

I'll need at least one pulley (a toothed wheel), that can be mounted to the motor drive shaft. At the other end of the rail, I can use a bearing to allow the belt to move freely.

The image below shows the belt mechanism at one end of the Adafruit slider. Note how a smooth bearing is used, not a toothed pulley:

![]({{site.baseurl}}/assets/3d_printing_belt-bearing-install.jpg)

Pulleys are specified by a given number of teeth, for a certain pitch of belt. e.g. a `30 tooth GT2 pulley`. I need a 5 mm bore for the motor drive shaft, with fixing via a grub screw, and a width of 6 mm or more for the 6 mm belt.

One factor I might want to  consider here is the diameter of the pulley. [According to Ooznest](https://ooznest.co.uk/product/gt2-pulleys/), a 30 tooth **GT3** pulley (note: the description here says GT3, not GT2, but I think that may be a typo) will allow the belt to loop around both sides of a 20 mm extrusion.

I plan to run the timing belt in the cavity between two rails of aluminium extrusion, so this may not be an issue. However, if I want to include an angled rod between the two rails to pivot the gantry along its traverse, I might want to use a bigger pulley to leave some space here. The pulley and the opposite-end bearing should have roughly the same diameter.

Fortunately, [it is possible to calculate the diameter of a pulley](https://www.pfeiferindustries.com/timing-belt-pulley-pitch-diameter-outside-diameter-charts) if you know the number of teeth and the pitch.

Diameter   
= Number of teeth * Pitch / Pi  
= 30 * 2 mm / 3.14  
= 19.1 mm

For a 20 tooth pulley, this works out at 12.7 mm. Obviously this gives you the diameter on the inside of the belt, so to check for clearances, you need to allow for the thickness of the belt, and also the diameter of any fences on the pulley.


It's [possible to laser-cut pulleys](http://fab.academany.org/2018/labs/fablabbrighton/students/andrew-sleigh/assignments/2018/05/09/wk15-machine-building.html), and I think this would be an experiment worth doing, to compare with commercially made pulleys.

Pulleys:

* [Adafruit Aluminum GT2 Timing Pulley - 6mm Belt - 36 Tooth - 5mm Bore](https://www.adafruit.com/product/1253): $12
* [Ooznest GT2 Pulley 20 Tooth](https://ooznest.co.uk/product/gt2-pulleys/): £2.90
* [Ooznest GT2 (**I think**) Pulley 30 Tooth](https://ooznest.co.uk/product/gt2-pulleys/): £8.75

Bearings:

* Ooznest only sell 5 mm wide bearings. If I'm using a 6 mm belt, these won't be big enough
* [Amazon 10 x 26 x 8 mm bearings, pack of 3](https://www.amazon.co.uk/Metallic-Sealed-Groove-Bearing-6000Z/dp/B07MX91G6Q/ref=lp_12465306031_1_12?s=industrial&ie=UTF8&qid=1555232155&sr=1-12&th=1) (£3.50)
* [RS have many 6-7 mm wide bearings at 19 mm diameter](https://uk.rs-online.com/web/c/pneumatics-hydraulics-power-transmission/power-transmission-rotary-bearings/ball-bearings/?searchTerm=bearings&applied-dimensions=4294536642,4294536636,4294845442&sort-by=P_breakPrice1&sort-order=asc&pn=1) (around £2 each)

You can also get 'idler pulleys', essentially a pulley mounted on a bearing, which might be a better choice for the end opposite the motor.

* Amazon: [20 teeth 5mm Bore 6mm width (Pack of 5)](https://www.amazon.co.uk/BIQU-20Teeth-Aluminum-Timing-Printer/dp/B06VSL9W9L/ref=sr_1_4?keywords=gt2+6mm+idler+pulley&qid=1555232994&s=industrial&sr=1-4) (£7)

Or you can buy complete kits of belts, pulleys and idler pulleys ([This, £15 on Amazon](https://www.amazon.co.uk/KeeYees-Timing-Tensioner-Torsion-Printer/dp/B07JGXG7S2/ref=sr_1_3?keywords=gt2+6mm+idler+pulley&qid=1555232994&s=industrial&sr=1-3), or [this, just the belt and 2 pulleys for £9](https://www.amazon.co.uk/JSDL-Timing-Pulley-2GT-6mm-Opening/dp/B06XQ333PN/ref=sr_1_16?keywords=gt2+pulley+6mm&qid=1555233238&s=industrial&sr=1-16))

### End caps / feet

WIP


### Controls and screen

WIP!

### End stops

I have some end-stop switches left over from a previous project.

### Tripod mount

This is a 'nice-to-have' feature, but shouldn't be difficult to implement. I just need a plate on the bottom of the rails with a threaded hole (or captured nut) to accept a 1/4" (or possibly 3/8") UNC threaded bolt. These are the [standard sizes for tripod mounts](http://www.photokonnexion.com/photography-thread-size/):

| Diameter (inch) | Diameter (mm) | Thread size |
| :-------------: | :-----------: | :---------: |
|       1/4       |    6.3500     |     20      |
|       3/8       |    7.9375     |     16      |

### Assembly brackets and casings

#### Motor

There are many [3D designs on Thingiverse](https://www.thingiverse.com/search?q=nema+17+bracket&dwh=1005cb30d3341f54).

The sketch at the top of the page shows the bare minimum I'd need to do to mount the motor to the rails in the right orientation. This needs more work, perhaps in Fusion 360.

#### Belt bearing

Unless I use an idler pulley (which has fences on either side of the rail), this might need some sort of guides to stop the belt sliding off the bearing.

Ideally, (as on the Adafruit slider bearing bracket) the bolts in this bracket should fit into slots, so the bracket itself can be moved back and forth to adjust belt tension (just like the rear wheel on a single speed bike).


#### Microcontroller and driver boards

I think for version 1, this could be an entirely separate assembly, since only an electrical connection is needed between the boards and the motor.


### Fixings

It would be nice if the design could standardise on one bolt size, say M5, with one head type. For example, if all bolts had Allen key heads of the same size, you could attach the correct key somewhere on the frame of the machine, for easy adjustment or tightening.

(Maybe I should get an assortment set?)


#### T Nuts and brackets?
