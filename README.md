# Compton_Scattering_Simulation
For "Laboratory Work in Physics A1(物理科学課題演習A1)" of Kyoto university, I wanted to know a effect of a angular resolution. Therefore, I made simulation of compton scattering.

How to use
-------------
1. Build the project or run x64\Release\LaBr_NaI_500000_revise4.exe, LaBr_NaI_5000000_revise4.exe, or LaBr_NaI_25000000_revise4.exe
> NOTE 500000, 5000000, and 25000000 mean a number of photons which you want to simulate.
2. The program ask whether you print animation or not. Enter 'y' if you want.
3. Enter a degree you want to simulate. Please select number from 0 to 180. Value over this range may not work.
4. Wait the end of simulation. If you entered 'y' on above, you probably see how photons move.
5. If command box says 'end!' then press any key on the animation screen. Then 'result.txt.' will be in the folder. First number means energy which is absorbed by LaBr<sub>3</sub>. Second number means energy which is absorbed by NaI.

Experiment Setting
-------------
<img src="/img/ex1.jpg"  width="49%" height="49%"> <img src="/img/ex2.jpg"  width="49%" height="49%"> 
* Above image is setting of the experiment. We used <sup>137</sup>Cs as a gamma ray source. Gamma ray enter to LaBr<sub>3</sub> scintillator. Then, after compton scattering, it fly to NaI scintillator. Distance from LaBr<sub>3</sub> and <sup>137</sup>Cs was 15cm. Distance from LaBr<sub>3</sub> and NaI was 30cm. Radius of LaBr<sub>3</sub> is 2.5cm. Radius of NaI is 2.75cm. At simulation, I considered geomatric things, like radius of NaI, or radius of <sup>137</sup>Cs, etc.

How does simulation work
-------------
I got graph of linear attenuation coefficient of LaBr and NaI from 
>Dorenbos, P., J. T. M. De Haas, and C. W. E. Van Eijk. "Gamma ray spectroscopy with a 019× 19 mm3 LaBr3: 0: 5% ce3+ scintillator." IEEE Trans. Nucl. Sci. 51.3 (2004).

However, I do not know how to calculate this value. So I just use the values of coefficient from graph. It probably makes some error on result. By this coefficient, I can calculate probability to undergo compton scattering and photoelectric absorption. Energy can be calculated by formula on compton scattering.

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
* Total events at 50 degree. Left is real experiment data. Right one is simulation result. Experiment data shows some peak on left side. It is probably due to back scattering
#
| Angle (degree) | Energy of NaI at the simulation (keV) | Energy of NaI at the experiment (keV) | Ideal Energy of NaI (keV) |
| :---: | :---: | :---: | :---: |
| 50 | 485.5 | 437.67 | 452.56 |
| 60 | 429 | 389.55 | 401.75 |
| 70 | 380 | 354.63 |357.37|
| 80 | 341 | 311.50 |319.72|
| 90 | 303 | 276.05 |288.38|
| 100 | 276 | 261.14 |262.65|
| 110 | 249 | 243.62 |241.73|
| 120 | 231.4 | 227.53 |224.92|
| 130 | 215.4 | 217.52 |211.62|
| 140 | 203.6 | 206.89 |201.34|
| 150 | 196 | 196.70 |193.71|
| 160 | 188.5 | 186.36 |188.44|
| 170 | 187.1 | 185.81 |185.36|
| 180 | 186.5 | 184.53 |184.34|
* Comparison among the simulation, experiment, ideal value(by Klein-Nishina formula). As you can see, simulation shows high discrepancy from ideal value and experiment data at low angle. It may be stem from error of attenuation coefficient value.
#
Used library
-------------
opencv
