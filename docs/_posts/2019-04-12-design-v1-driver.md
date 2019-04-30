---
permalink: design-v1-driver/
title: Designing version 1 – Stepper motor driver
date: 2019-04-12
author: Andrew
layout: page
sort_id: 33
---

I don't know if it's actually possible to drive a stepper motor directly from an Arduino, but certainly all the projects I've seen use a separate driver chip on another board that can be connected to the microcontroller.

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


There is another Allegro chip, the [A4988](https://cdn.sparkfun.com/datasheets/Robotics/A4988-Datasheet.pdf), which is rated to 35 V and 2 A.

* This is used in Sparkfun's [Big Easy Driver](https://www.sparkfun.com/products/12859) ($20)
* Pololu also have a much cheaper board: [A4988 Stepper Motor Driver Carrier](https://www.pololu.com/product/1182) $6

Adafruit have a nice board, the [Motor/Stepper/Servo Shield for Arduino v2 Kit - v2.3](https://www.adafruit.com/product/1438), based on the TB6612, which can drive up to two steppers at 1.2 A per channel. This is $20, so comparable to other brand-name boards that can only drive one stepper.

There are many others, including the [STMicroelectronics L293D](http://www.st.com/st-web-ui/static/active/en/resource/technical/document/datasheet/CD00000059.pdf) used in the [Adafruit Arduino Motor Shield](http://www.adafruit.com/index.php?main_page=product_info&products_id=81) and [Toshiba TB6600](http://www.semicon.toshiba.com.cn/info/docget.jsp?type=Catalog1&lang=en&pid=TB6600HG) used in the [PiBot TB6600 Stepper Driver](http://reprap.org/wiki/PiBot_TB6600_Stepper_Driver) and also in the _fab-able_ [satstep6600](https://github.com/satstep/satstep6600).

[Reprap also has a good list of different driver chips.](https://reprap.org/wiki/Stepper_motor_driver)

I went with a generic A4988-based board, originally one from Ooznest, which I fried, and then one from Elegoo ([£11 for 5 boards](https://www.amazon.co.uk/Stepper-Stepstick-Headsink-Arduino-Machines/dp/B07B9ZKST7/ref=sr_1_5?keywords=a4988&qid=1556133738&s=gateway&sr=8-5)). This is a clone of the RepRap [StepStick board](https://reprap.org/wiki/StepStick).
