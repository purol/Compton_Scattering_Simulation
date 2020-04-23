# include <stdio.h>
# include <math.h>
# include <time.h>
# include <stdlib.h>
# include <opencv2/opencv.hpp>

# define initial_num 500000
# define pi 3.1415926535
# define delx 0.0005
// # define mu_Labr 34.6

# define times 1000
# define center_x 400
# define center_y 500
# define z_limit 0.032
# define distance_limit 0.4

# define convert (3.141592/180.0)

int N = initial_num;
int N_temp;

typedef struct photon {
	double x;
	double y;
	double z;
	double theta;
	double phi;
	bool react;
	bool stop;
	bool life;
	bool NaI_react;
	double energy; // kev
	double LaBr;
	double NaI;
} Photon;

using namespace cv;
using namespace std;

void initialization(Photon pho[]);
void movement(Photon pho[]);
void collide_LaBr(Photon pho[]);
void collide_NaI(Photon pho[]);
double dif_sca(double angle, double energy);
double rev_to_pi(double x);
double rev_to_2pi(double x);
double LaBr_mu_photoelectric(double energy);
bool checki_validity(Photon pho[]);
void print_photon(Photon pho[], InputOutputArray img);
void photon_progress(Photon pho[]);
double LaBr_mu_compton(double energy);
double NaI_mu_photoelectric(double energy);
double NaI_mu_compton(double energy);


double angl = 80 * convert;

int main(int argc, char* argv[]) {
	srand(time(NULL));

	Mat image = Mat::zeros(700, 800, CV_8UC3);

	char letter; bool show = false;
	while (1) {
		printf("Do you want to see simulation? (y/n)\n");
		letter = getchar();
		if (letter == 'y') {
			printf("Simulation On\n\n"); 
			show = true;
			break;
		}
		else if (letter == 'n') {
			printf("Simulation Off?\n\n"); 
			break;
		}
	}
	
	printf("Enter degree which you want to simulate\n");
	scanf_s("%lf", &angl,sizeof(angl));
	angl = angl * convert;


	Photon * pho = (Photon*)malloc(sizeof(Photon) * N);
	initialization(pho);

	Photon* pho_temp = NULL;
	N_temp = initial_num;

		for (;;) {

			photon_progress(pho);

	if (show == true) {
		image = cv::Scalar(255, 255, 255);

		print_photon(pho, image);

		rectangle(image, Point(center_x + times * 0.025, center_y - times * 0.153 + times * 0.025), Point(center_x - times * 0.025, center_y - times * 0.153 - times * 0.025), Scalar(0, 0, 0));
		line(image, Point(center_x + times * (-0.355 * sin(angl) - 0.0275 * cos(angl)), center_y + times * (-0.15 - 0.355 * cos(angl) + 0.0275 * sin(angl))), Point(center_x + times * (-0.355 * sin(angl) + 0.0275 * cos(angl)), center_y + times * (-0.15 - 0.355 * cos(angl) - 0.0275 * sin(angl))), Scalar(0, 0, 0));
		line(image, Point(center_x + times * (-0.3 * sin(angl) - 0.0275 * cos(angl)), center_y + times * (-0.15 - 0.3 * cos(angl) + 0.0275 * sin(angl))), Point(center_x + times * (-0.3 * sin(angl) + 0.0275 * cos(angl)), center_y + times * (-0.15 - 0.3 * cos(angl) - 0.0275 * sin(angl))), Scalar(0, 0, 0));
		line(image, Point(center_x + times * (-0.355 * sin(angl) - 0.0275 * cos(angl)), center_y + times * (-0.15 - 0.355 * cos(angl) + 0.0275 * sin(angl))), Point(center_x + times * (-0.3 * sin(angl) - 0.0275 * cos(angl)), center_y + times * (-0.15 - 0.3 * cos(angl) + 0.0275 * sin(angl))), Scalar(0, 0, 0));
		line(image, Point(center_x + times * (-0.355 * sin(angl) + 0.0275 * cos(angl)), center_y + times * (-0.15 - 0.355 * cos(angl) - 0.0275 * sin(angl))), Point(center_x + times * (-0.3 * sin(angl) + 0.0275 * cos(angl)), center_y + times * (-0.15 - 0.3 * cos(angl) - 0.0275 * sin(angl))), Scalar(0, 0, 0));
		imshow("Display Window", image);
		waitKey(1);
		if (checki_validity(pho) == false) {
			printf("end!\n");
			waitKey(0);
			break;
		}
	}
	else {
		if (checki_validity(pho) == false) {
			printf("end!\n");
			break;
		}
	}

	if (N != N_temp) {
		pho_temp = (Photon*)malloc(sizeof(Photon) * N_temp);
		int j = 0;

		for (int i = 0; i < N; i++) {
			if (pho[i].life == true) {
				pho_temp[j].x = pho[i].x;
				pho_temp[j].y = pho[i].y;
				pho_temp[j].z = pho[i].z;
				pho_temp[j].theta = pho[i].theta;
				pho_temp[j].phi = pho[i].phi;
				pho_temp[j].react = pho[i].react;
				pho_temp[j].stop = pho[i].stop;
				pho_temp[j].life = pho[i].life;
				pho_temp[j].NaI_react = pho[i].NaI_react;
				pho_temp[j].energy = pho[i].energy;
				pho_temp[j].LaBr = pho[i].LaBr;
				pho_temp[j].NaI = pho[i].NaI;

				j = j + 1;
			}
		}
		free(pho); 
		pho = NULL;
		pho = pho_temp;
		pho_temp = NULL;
		N = N_temp;
	}

		}


	FILE* fp;
	fopen_s(&fp, "result.txt", "w");
	fprintf_s(fp,"degree : %.2lf\n", angl*180/pi);
	for (int i = 0; i < N; i++) {
		if (pho[i].NaI_react == true) {
			fprintf_s(fp, "%f %f\n", pho[i].LaBr, pho[i].NaI);
		}

	}
	fclose(fp);
	free(pho);

	return 0;
}

void initialization(Photon pho[]) {
	for (int i = 0; i < N; i++) {
		double r = (rand() / 32768.0) * 0.005;
		double angle_Cs = (rand() / 32768.0) * 2 * pi;
		pho[i].x = r*cos(angle_Cs);
		pho[i].y = 0;
		pho[i].z = r*sin(angle_Cs);
		pho[i].theta = 0.56 * (rand() / 32768.0)+0.5*pi-0.28;
		pho[i].phi = 0.56 * (rand() / 32768.0) + 1.5*pi-0.28;
		pho[i].react = false;
		pho[i].stop = false;
		pho[i].life = true;
		pho[i].NaI_react = false;
		pho[i].energy = 662;
		pho[i].LaBr = 0;
		pho[i].NaI = 0;
		
	}
}

void movement(Photon pho[]) {
	int i = 0;
	for (int i = 0; i < N; i++) {
		if (pho[i].stop == false) {
			pho[i].x = pho[i].x + delx * sin(pho[i].theta) * cos(pho[i].phi);
			pho[i].y = pho[i].y + delx * sin(pho[i].theta) * sin(pho[i].phi);
			pho[i].z = pho[i].z + delx * cos(pho[i].theta);
			if (pho[i].z > z_limit || pho[i].z < -z_limit && pho[i].life == true) {
				pho[i].stop = true;
				if (pho[i].NaI_react == false) {
					pho[i].life = false;
					N_temp = N_temp - 1;
				}
			}
			else if (sqrt(pho[i].x * pho[i].x + (pho[i].y + 0.15) * (pho[i].y + 0.15) + pho[i].z * pho[i].z) > distance_limit && pho[i].life==true) {
				pho[i].stop = true;
				if (pho[i].NaI_react == false) {
					pho[i].life = false;
					N_temp = N_temp - 1;
				}
			}
			else if (pho[i].react == false && sqrt(pho[i].x * pho[i].x + pho[i].y * pho[i].y + pho[i].z * pho[i].z) > 0.202 && pho[i].life == true) {
				pho[i].stop = true;
				if (pho[i].NaI_react == false) {
					pho[i].life = false;
					N_temp = N_temp - 1;
				}
			}
			else if (pho[i].react == false && sqrt(pho[i].x * pho[i].x + (pho[i].z-0.005) * (pho[i].z-0.005)) > 0.025 && pho[i].life == true) {
				pho[i].stop = true;
				if (pho[i].NaI_react == false) {
					pho[i].life = false;
					N_temp = N_temp - 1;
				}
			}
		}
	}
}

void collide_LaBr(Photon pho[]) {
	int i = 0;
	for (int i = 0; i < N; i++) {
		if (pho[i].stop == false && pho[i].y > -0.178 && pho[i].y < -0.128 && sqrt(pho[i].x * pho[i].x + (pho[i].z-0.005) * (pho[i].z-0.005)) < 0.025) { //0.025

			if (rand() / 32768.0 < delx * (LaBr_mu_compton(pho[i].energy) + LaBr_mu_photoelectric(pho[i].energy))) {
				double mu1 = LaBr_mu_photoelectric(pho[i].energy);
				double mu2 = LaBr_mu_compton(pho[i].energy);

				if (rand() / 32768.0 < mu2/(mu1+mu2)) { // start to compton
					pho[i].react = true;
					bool flag = false;
					double phi = 0;
					double theta = 0;
					double theta_c = 0;
					while (!flag) {
						phi = 2 * pi * rand() / 32768.0;
						theta = pi * rand() / 32768.0;
						double prob = rand() / 32768.0;
						theta_c = acos(sin(pho[i].theta) * sin(theta) * cos(pho[i].phi) * cos(phi) + sin(pho[i].theta) * sin(theta) * sin(pho[i].phi) * sin(phi) + cos(pho[i].theta) * cos(theta));
						theta_c = rev_to_pi(theta_c);
						if (prob < dif_sca(theta_c, pho[i].energy)) flag = true;
					}
					pho[i].theta = theta;
					pho[i].phi = phi;
					double energy_temp = pho[i].energy;
					pho[i].energy = energy_temp / (1 + (1 - cos(theta_c)) * energy_temp / 511.0);
					pho[i].LaBr = pho[i].LaBr + energy_temp - pho[i].energy;
				}
				else { // start to photoelectric
					pho[i].react = true;
					double energy_temp = pho[i].energy;
					pho[i].energy = 0;
					pho[i].LaBr = pho[i].LaBr + energy_temp - pho[i].energy;
					pho[i].stop = true;
				}

			}


		}
	}
}

void collide_NaI(Photon pho[]) {
	int i = 0;
	for (int i = 0; i < N; i++) if(pho[i].stop == false && pho[i].react == true) {
		double dummy = pho[i].y + pho[i].x * tan(angl);
		double distance = 0;
		double distance1 = 0; double distance2 = 0;
		distance2 = fabs(pho[i].z-0.0025);
		distance1 = sin(angl) * (pho[i].x / tan(angl) - pho[i].y - 0.15);
		distance = sqrt(distance1 * distance1 + distance2 * distance2);
		double dummy2 = -0.15 - 0.355 * cos(angl) - 0.355 * sin(angl) * sin(angl) / cos(angl);
		double dummy3 = -0.15 - 0.3 * cos(angl) - 0.3 * sin(angl) * sin(angl) / cos(angl);
		if (tan(angl)>0 && distance <= 0.0275 && dummy>=dummy2 && dummy<=dummy3) { //0.0275

			if (rand() / 32768.0 < delx * (NaI_mu_compton(pho[i].energy) + NaI_mu_photoelectric(pho[i].energy))) {
				double mu1 = NaI_mu_photoelectric(pho[i].energy);
				double mu2 = NaI_mu_compton(pho[i].energy);

				if (rand() / 32768.0 < mu1 / (mu1 + mu2)) { // start to photoelectric
					pho[i].stop = true;
					pho[i].NaI = pho[i].NaI + pho[i].energy;
					pho[i].energy = 0;
					pho[i].NaI_react = true;
				}
				else { // start to compton
					pho[i].NaI_react = true;
					bool flag = false;
					double phi = 0;
					double theta = 0;
					double theta_c = 0;
					while (!flag) {
						phi = 2 * pi * rand() / 32768.0;
						theta = pi * rand() / 32768.0;
						double prob = rand() / 32768.0;
						theta_c = acos(sin(pho[i].theta) * sin(theta) * cos(pho[i].phi) * cos(phi) + sin(pho[i].theta) * sin(theta) * sin(pho[i].phi) * sin(phi) + cos(pho[i].theta) * cos(theta));
						theta_c = rev_to_pi(theta_c);
						if (prob < dif_sca(theta_c, pho[i].energy)) flag = true;
					}
					pho[i].theta = theta;
					pho[i].phi = phi;
					double energy_temp = pho[i].energy;
					pho[i].energy = energy_temp / (1 + (1 - cos(theta_c)) * energy_temp / 511.0);
					pho[i].NaI = pho[i].NaI + energy_temp - pho[i].energy;
				}
			}

		}
		else if (tan(angl) < 0 && distance <= 0.0275 && dummy <= dummy2 && dummy >= dummy3) {

			if (rand() / 32768.0 < delx * (NaI_mu_compton(pho[i].energy) + NaI_mu_photoelectric(pho[i].energy))) {
				double mu1 = NaI_mu_photoelectric(pho[i].energy);
				double mu2 = NaI_mu_compton(pho[i].energy);

				if (rand() / 32768.0 < mu1 / (mu1 + mu2)) { // start to photoelectric
					pho[i].stop = true;
					pho[i].NaI = pho[i].NaI + pho[i].energy;
					pho[i].energy = 0;
					pho[i].NaI_react = true;
				}
				else { // start to compton
					pho[i].NaI_react = true;
					bool flag = false;
					double phi = 0;
					double theta = 0;
					double theta_c = 0;
					while (!flag) {
						phi = 2 * pi * rand() / 32768.0;
						theta = pi * rand() / 32768.0;
						double prob = rand() / 32768.0;
						theta_c = acos(sin(pho[i].theta) * sin(theta) * cos(pho[i].phi) * cos(phi) + sin(pho[i].theta) * sin(theta) * sin(pho[i].phi) * sin(phi) + cos(pho[i].theta) * cos(theta));
						theta_c = rev_to_pi(theta_c);
						if (prob < dif_sca(theta_c, pho[i].energy)) flag = true;
					}
					pho[i].theta = theta;
					pho[i].phi = phi;
					double energy_temp = pho[i].energy;
					pho[i].energy = energy_temp / (1 + (1 - cos(theta_c)) * energy_temp / 511.0);
					pho[i].NaI = pho[i].NaI + energy_temp - pho[i].energy;
				}

			}

		}
		else if (tan(angl) == 0 && cos(angl)>0 && sqrt(pho[i].x * pho[i].x + (pho[i].z-0.0025) * (pho[i].z-0.0025)) <= 0.0275 && pho[i].y<=-0.45 && pho[i].y>=-0.505) {

			if (rand() / 32768.0 < delx * (NaI_mu_compton(pho[i].energy) + NaI_mu_photoelectric(pho[i].energy))) {
				double mu1 = NaI_mu_photoelectric(pho[i].energy);
				double mu2 = NaI_mu_compton(pho[i].energy);

				if (rand() / 32768.0 < mu1 / (mu1 + mu2)) { // start to photoelectric
					pho[i].stop = true;
					pho[i].NaI = pho[i].NaI + pho[i].energy;
					pho[i].energy = 0;
					pho[i].NaI_react = true;
				}
				else { // start to compton
					pho[i].NaI_react = true;
					bool flag = false;
					double phi = 0;
					double theta = 0;
					double theta_c = 0;
					while (!flag) {
						phi = 2 * pi * rand() / 32768.0;
						theta = pi * rand() / 32768.0;
						double prob = rand() / 32768.0;
						theta_c = acos(sin(pho[i].theta) * sin(theta) * cos(pho[i].phi) * cos(phi) + sin(pho[i].theta) * sin(theta) * sin(pho[i].phi) * sin(phi) + cos(pho[i].theta) * cos(theta));
						theta_c = rev_to_pi(theta_c);
						if (prob < dif_sca(theta_c, pho[i].energy)) flag = true;
					}
					pho[i].theta = theta;
					pho[i].phi = phi;
					double energy_temp = pho[i].energy;
					pho[i].energy = energy_temp / (1 + (1 - cos(theta_c)) * energy_temp / 511.0);
					pho[i].NaI = pho[i].NaI + energy_temp - pho[i].energy;
				}
			}

		}
		else if (tan(angl) == 0 && cos(angl) < 0 && sqrt(pho[i].x * pho[i].x + (pho[i].z-0.0025) * (pho[i].z-0.0025)) <= 0.0275 && pho[i].y <= 0.205 && pho[i].y >= 0.15) {

		if (rand() / 32768.0 < delx * (NaI_mu_compton(pho[i].energy) + NaI_mu_photoelectric(pho[i].energy))) {
			double mu1 = NaI_mu_photoelectric(pho[i].energy);
			double mu2 = NaI_mu_compton(pho[i].energy);

			if (rand() / 32768.0 < mu1 / (mu1 + mu2)) { // start to photoelectric
				pho[i].stop = true;
				pho[i].NaI = pho[i].NaI + pho[i].energy;
				pho[i].energy = 0;
				pho[i].NaI_react = true;
			}
			else { // start to compton
				pho[i].NaI_react = true;
				bool flag = false;
				double phi = 0;
				double theta = 0;
				double theta_c = 0;
				while (!flag) {
					phi = 2 * pi * rand() / 32768.0;
					theta = pi * rand() / 32768.0;
					double prob = rand() / 32768.0;
					theta_c = acos(sin(pho[i].theta) * sin(theta) * cos(pho[i].phi) * cos(phi) + sin(pho[i].theta) * sin(theta) * sin(pho[i].phi) * sin(phi) + cos(pho[i].theta) * cos(theta));
					theta_c = rev_to_pi(theta_c);
					if (prob < dif_sca(theta_c, pho[i].energy)) flag = true;
				}
				pho[i].theta = theta;
				pho[i].phi = phi;
				double energy_temp = pho[i].energy;
				pho[i].energy = energy_temp / (1 + (1 - cos(theta_c)) * energy_temp / 511.0);
				pho[i].NaI = pho[i].NaI + energy_temp - pho[i].energy;
			}
		}

		}

	}
}

double dif_sca(double angle, double energy) { //angle at radius, energy at kev
	double dum = 1 + (energy / 511.0) * (1 - cos(angle));
	return 0.5 * (1 / (dum * dum)) * (dum + 1 / dum - pow(sin(angle), 2));
}

double rev_to_pi(double x) {
	while (x < 0 || x >= pi) {
		if (x < 0) x = x + pi;
		else if (x >= pi) x = x - pi;
	}
	return x;
}

double rev_to_2pi(double x) {
	while (x < 0 || x >= 2 * pi) {
		if (x < 0) x = x + 2 * pi;
		else if (x >= 2 * pi) x = x - 2 * pi;
	}
	return x;
}

double LaBr_mu_photoelectric(double energy) { // energy kev 
	double dum = log10(energy);
	
	if (dum <= 1.128) return 100 * pow(10, -2.46875 * dum + 5.15275);
	else if (dum > 1.128 && dum <= 1.587)return 100 * pow(10, -2.68409 * dum + 5.81766);
	else if (dum >= 1.587 && dum <= 2.477)return 100 * pow(10, -2.81797 * dum + 6.35713);
	else return 100 * pow(10, -2.54941 * dum + 5.69190);
}

double NaI_mu_photoelectric(double energy) { // energy kev
	double dum = log10(energy);

	if (dum <= 1.516) return 100 * pow(10, -2.75 * dum + 5.434);
	else if (dum > 1.516 && dum <= 2.477) return 100 * pow(10, -2.74817 * dum + 6.18423);
	else return 100 * pow(10, -2.54941 * dum + 5.69190);

}

double LaBr_mu_compton(double energy) { // energy kev 
	double dum = log10(energy);

	if (dum <= 1.809) return 100 * pow(10, -0.375412 * (dum - 1.809) * (dum - 1.809) - 0.2193);
	else return 100 * pow(10, -0.248403 * (dum - 1.809) * (dum - 1.809) - 0.2193);

}

double NaI_mu_compton(double energy) { // energy kev 
	double dum = log10(energy);
if(dum<=1.826) return 100 * pow(10, -0.360265 * (dum - 1.826) * (dum - 1.826) - 0.3772);
else return 100 * pow(10, -0.265852 * (dum - 1.826) * (dum - 1.826) - 0.3772);

}
	
bool checki_validity(Photon pho[]) {
	bool result = false;
	for (int i = 0; i < N; i++) {
		if (pho[i].stop == false) {
			result = true;
			break;
		}
	}
	return result;
}

void print_photon(Photon pho[], InputOutputArray img) { // B G R
	for (int i = 0; i < N; i++) {
		if (pho[i].stop == false) {
			if (pho[i].react == false) circle(img, Point((int)times * pho[i].x + center_x, (int)times * pho[i].y + center_y), 1, Scalar(0, 0, 0), -100);
			else if (pho[i].react == true && pho[i].stop == false) circle(img, Point((int)times * pho[i].x + center_x, (int)times * pho[i].y + center_y), 1, Scalar(204, 0, 0), -100); // B G R
		}
		else if (pho[i].NaI > 0) circle(img, Point((int)times * pho[i].x + center_x, (int)times * pho[i].y + center_y), 1, Scalar(0, 204, 0), -100);
	}
}

void photon_progress(Photon pho[]) {
	movement(pho);
	collide_LaBr(pho);
	collide_NaI(pho);
}