# Compton_Scattering_Simulation
For "Laboratory Work in Physics A1(物理科学課題演習A1)" of Kyoto university. I wanted to know a effect of a angular resolution. Therefore, I made simulation of compton scattering.

How to use
-------------
1. Build the project or run x64\Release\LaBr_NaI_500000_revise4.exe, LaBr_NaI_5000000_revise4.exe, or LaBr_NaI_25000000_revise4.exe
> NOTE 500000, 5000000, and 25000000 mean a number of photons which you want to simulate.
2. The program ask whether you print animation or not. Enter 'y' if you want.
3. Enter a degree you want to simulate. Please select number from 0 to 180. Value over this range may not work.
4. Wait the end of simulation. If you entered 'y' on above, you probably see how photons move.
5. If command box says 'end!' then press any key on the animation screen. Then 'result.txt.' will be in the folder. First number means energy which is absorbed by LaBr<sub>3</sub>. Second number means energy which is absorbed by NaI.

Running Image
-------------
<img src="/img/animation2.webp"  width="70%" height="70%"> 
<img src="/img/animation1.webp"  width="70%" height="70%">
<img src="/img/animation3.webp"  width="70%" height="70%">
<!--![Alt text](/img/animation2.webp "0")
![Alt text](/img/animation1.webp "1") 
![Alt text](/img/animation3.webp "2") -->

Result
-------------
<img src="/img/deg10_sim.png"  width="49%" height="49%"> <img src="/img/deg20_sim.png"  width="49%" height="49%"> 
* Black dot is real experiment data. Red dot is result of simulation. (left:degree10, right:degree20)
#
<img src="/img/deg30_sim.png"  width="49%" height="49%"> <img src="/img/deg40_sim.png"  width="49%" height="49%"> 
* Black dot is real experiment data. Red dot is result of simulation. (left:degree30, right:degree40)
#
<img src="/img/deg50_sim.png"  width="49%" height="49%"> <img src="/img/deg60_sim.png"  width="49%" height="49%"> 
* Black dot is real experiment data. Red dot is result of simulation. (left:degree50, right:degree60)
#
<img src="/img/deg70_sim.png"  width="49%" height="49%"> <img src="/img/deg80_sim.png"  width="49%" height="49%"> 
* Black dot is real experiment data. Red dot is result of simulation. (left:degree70, right:degree80)
#
<img src="/img/deg90_sim.png"  width="49%" height="49%"> <img src="/img/deg100_sim.png"  width="49%" height="49%"> 
* Black dot is real experiment data. Red dot is result of simulation. (left:degree90, right:degree100)
#
<img src="/img/deg110_sim.png"  width="49%" height="49%"> <img src="/img/deg120_sim.png"  width="49%" height="49%"> 
* Black dot is real experiment data. Red dot is result of simulation. (left:degree110, right:degree120)
#
<img src="/img/deg130_sim.png"  width="49%" height="49%"> <img src="/img/deg140_sim.png"  width="49%" height="49%"> 
* Black dot is real experiment data. Red dot is result of simulation. (left:degree130, right:degree140)
#
<img src="/img/deg150_sim.png"  width="49%" height="49%"> <img src="/img/deg160_sim.png"  width="49%" height="49%"> 
* Black dot is real experiment data. Red dot is result of simulation. (left:degree150, right:degree160)
#
<img src="/img/deg170_sim.png"  width="49%" height="49%"> <img src="/img/deg180_sim.png"  width="49%" height="49%"> 
* Black dot is real experiment data. Red dot is result of simulation. (left:degree170, right:degree180)
#
<img src="/img/without_comp/deg50_ex.png"  width="49%" height="49%"> <img src="/img/without_comp/deg50_sim.png"  width="49%" height="49%"> 
<img src="/img/without_comp/deg50_ex_labr.png"  width="49%" height="49%"> <img src="/img/without_comp/deg50_sim_labr.png"  width="49%" height="49%"> 
<img src="/img/without_comp/deg50_ex_nai.png"  width="49%" height="49%"> <img src="/img/without_comp/deg50_sim_nai.png"  width="49%" height="49%"> 
* Events that photons undergo compton scattering on LaBr<sub>3</sub> and photoelectric absorbtion on NaI at 50 degree. Left is real experiment data. Right one is simulation result.
#
<img src="/img/with_comp/deg50_ex.png"  width="49%" height="49%"> <img src="/img/with_comp/deg50_sim.png"  width="49%" height="49%"> 
<img src="/img/with_comp/deg50_ex_labr.png"  width="49%" height="49%"> <img src="/img/with_comp/deg50_sim_labr.png"  width="49%" height="49%"> 
<img src="/img/with_comp/deg50_ex_nai.png"  width="49%" height="49%"> <img src="/img/with_comp/deg50_sim_nai.png"  width="49%" height="49%"> 
* Total events at 50 degree. Left is real experiment data. Right one is simulation result. Experiment data show some peak on left side. It is probably due to back scattering
#

Used library
-------------
opencv
