/*void toprectangels() {
	int z = sqrt(moving_rectangels.tedad);
	int k = (ellips.left + ellips.right) / 2;
	int t1 = z;
	int t2 = t1;
	moving_rectangels.x.left = 0;
	moving_rectangels.x.right = console_size_x / z;
	moving_rectangels.x.up = 10;
	moving_rectangels.x.down = 60;
	int d = moving_rectangels.x.right - moving_rectangels.x.left;
	int v = 0;
	while (t1 > 0) {
		if (ellips.up <= moving_rectangels.x.down && k >= moving_rectangels.x.left && k <= moving_rectangels.x.right && moving_rectangels.lives.life > 0) {
			//moving_rectangels.lives.life = 0;
			//system("cls");
			//y = 2;
			u[n] = (moving_rectangels.x.left + moving_rectangels.x.right) / 2;
			//printf("%d", u[n]);
			n++;
		}
		//if (moving_rectangels.lives.life != 0&&t2>0)
		e = (moving_rectangels.x.left + moving_rectangels.x.right) / 2;
		for (int i = 0; i <= 14; i++) {
			if (e != u[i]) {
				//Rectangle(hdc, moving_rectangels.x.left, moving_rectangels.x.up, moving_rectangels.x.right, moving_rectangels.x.down);
			}
		}
			//if (e != (moving_rectangels.x.left + moving_rectangels.x.right) / 2)
			//	Rectangle(hdc, moving_rectangels.x.left, moving_rectangels.x.up, moving_rectangels.x.right, moving_rectangels.x.down);

		//}

		moving_rectangels.x.left = moving_rectangels.x.right;
		moving_rectangels.x.right += d;
		j++;
		t1--;
	}
}*/

/*void toprectangels() {
	int d = moving_rectangels.x.right - moving_rectangels.x.left;
	int k = (ellips.left + ellips.right) / 2;
	//for (int i = 0; i <= 14; i++) {
	if (p <= 14) {
		u[p] = (moving_rectangels.x.left + moving_rectangels.x.right) / 2;
		moving_rectangels.x.left = moving_rectangels.x.right;
		moving_rectangels.x.right += d;
		//printf("%d_", u[p]);
		p++;
	}
	if (ellips.up <= 60) {
		//printf("%d_", k);
		min = abs(u[3] - k);
		for (int i = 0; i <= 14; i++) {
			d = u[i] - k;
			if (d < 0) {
				d *= -1;
			}
			if (d <= min) {
				min = d;
				mk = i;
				//printf("%d\n", mk);
			}
			if (u[i] != 0) {
				Rectangle(hdc, u[i] - (d / 2), 10, u[i] + (d / 2), 60);
			}
		}
		u[mk] = 0;
		system("cls");
		y = 3;
		printf("%d\n", mk);
	}
	//system("color 3a");
		/*if (e <= 14) {
				if (u[e] != 0) {
			Rectangle(hdc, u[e] - (d / 2), 10, u[e] + (d / 2), 60);
				}
		}
		e++;
}*/
/*void toprectangels() {
	int x[100];
	int y[3];
	int d = (moving_rectangels.x.right - moving_rectangels.x.left);
	int dl = (moving_rectangels.x.down - moving_rectangels.x.up);
	int width = sqrt(moving_rectangels.tedad);
	while (n <= 2) {
		while (e <= width) {
			Rectangle(hdc, moving_rectangels.x.left, moving_rectangels.x.up, moving_rectangels.x.right, moving_rectangels.x.down);
			moving_rectangels.x.left = moving_rectangels.x.right;
			moving_rectangels.x.right += d;
			e++;
		}
		moving_rectangels.x.left = 0;
		moving_rectangels.x.right = console_size_x / width;
		e = 0;
		moving_rectangels.x.up += dl;
		moving_rectangels.x.down += dl;
		n++;
	}
}*/
/*if (ellips.left<center[i_z][0] + d / 2 && zl>center[i_z][1] - dl / 2 && zl < center[i_z][1] + dl / 2 && center[i_z][2] != 0) {
			if (abs(center[i_z][0] - z) <= R_e + d / 2 && abs(center[i_z][1] - zl) <= R_e + dl / 2) {
				SelectObject(hdc, GetStockObject(BLACK_BRUSH));
				Rectangle(hdc, center[i_z][0] - d / 2, center[i_z][1] - dl / 2, center[i_z][0] + d / 2, center[i_z][1] + dl / 2);
				x *= -1;
				center[i_z][2] = 0;
				live_number--;
			}
		}
		if (ellips.right > center[i_z][0] - d / 2 && zl > center[i_z][1] - dl / 2 && zl < center[i_z][1] + dl / 2 && center[i_z][2] != 0) {
			if (abs(center[i_z][0] - z) <= R_e + d / 2 && abs(center[i_z][1] - zl) <= R_e + dl / 2) {
				SelectObject(hdc, GetStockObject(BLACK_BRUSH));
				Rectangle(hdc, center[i_z][0] - d / 2, center[i_z][1] - dl / 2, center[i_z][0] + d / 2, center[i_z][1] + dl / 2);
				x *= -1;
				center[i_z][2] = 0;
				live_number--;
			}
		}
		  if (ellips.up<=center[i_z][1] + dl / 2 && z>=center[i_z][0] - d / 2 && z <= center[i_z][0] + d / 2&& center[i_z][2] != 0) {
			if (abs(center[i_z][0] - z) <= R_e + d / 2 && abs(center[i_z][1] - zl) <= R_e + dl / 2) {
				SelectObject(hdc, GetStockObject(BLACK_BRUSH));
				Rectangle(hdc, center[i_z][0] - d / 2, center[i_z][1] - dl / 2, center[i_z][0] + d / 2, center[i_z][1] + dl / 2);
				y *=-1;
				center[i_z][2] = 0;
				live_number--;
			}
		}
		 if (ellips.down > center[i_z][1] - dl / 2 && z > center[i_z][0] - d / 2 && z < center[i_z][0] + d / 2 && center[i_z][2] != 0) {
			if (abs(center[i_z][0] - z) <= R_e + d / 2 && abs(center[i_z][1] - zl) <= R_e + dl / 2) {
				SelectObject(hdc, GetStockObject(BLACK_BRUSH));
				Rectangle(hdc, center[i_z][0] - d / 2, center[i_z][1] - dl / 2, center[i_z][0] + d / 2, center[i_z][1] + dl / 2);
				y *= -1;
				center[i_z][2] = 0;
				live_number--;
			}
		}*/
		/*while (i_x < wdth) {
				while (i_y <= moving_rectangels.tadad_y*wdth) {
					center[i_y][1] = (moving_rectangels.x.down + moving_rectangels.x.up) / 2;
					i_y++;
					if (i_y % (wdth+gh) == 0) {
						moving_rectangels.x.up += dl;
						moving_rectangels.x.down += dl;
						gh += wdth;
					}

				}
				center[i_x][0] = (moving_rectangels.x.left + moving_rectangels.x.right) / 2;
				i_x++;
				moving_rectangels.x.left = moving_rectangels.x.right;
				moving_rectangels.x.right += d;
			}
			for (int i = 0; i < 30; i++) {
				center[i + wdth][0] = center[i][0];
			}*/
			/*for (int i = 0; i < 3 * wdth; i++) {
				if(center[i][2]!=0)
				Rectangle(hdc, center[i][0] - d / 2, center[i][1] - dl / 2, center[i][0] + d / 2, center[i][1] + dl / 2);
			}*/
/*void drowing_rectangels() {
	int d = (moving_rectangels.x.right - moving_rectangels.x.left);
	int dl = (moving_rectangels.x.down - moving_rectangels.x.up);
	while (n < moving_rectangels.tadad_y) {
		while (e < moving_rectangels.tedad_x) {
			SelectObject(hdc, GetStockObject(LTGRAY_BRUSH));
			Rectangle(hdc, moving_rectangels.x.left, moving_rectangels.x.up, moving_rectangels.x.right, moving_rectangels.x.down);
			moving_rectangels.x.left = moving_rectangels.x.right;
			moving_rectangels.x.right += d;
			e++;
		}
		moving_rectangels.x.left = 0;
		moving_rectangels.x.right = console_size_x / moving_rectangels.tedad_x;
		e = 0;
		moving_rectangels.x.up += dl;
		moving_rectangels.x.down += dl;
		n++;
	}
}*/
/*if (zl == (center[i_z][1] + center[i_z][1]+dl) / 2&&abs(center[i_z][0]-z)<d/2+R_e) {
					x *= -1;
					SelectObject(hdc, GetStockObject(BLACK_BRUSH));
					Rectangle(hdc, center[i_z][0] - d / 2, center[i_z][1] - dl / 2, center[i_z][0] + d / 2, center[i_z][1] + dl / 2);
					Rectangle(hdc, center[i_z][0] - d / 2, center[i_z][1] + dl / 2, center[i_z][0] + d / 2, center[i_z + 1][1] + 3*dl / 2);
					live_number -= 2;
					center[i_z][2] = 0;
					for (int i = 0; i < moving_rectangels.tadad_y*moving_rectangels.tedad_x; i++) {
						if (center[i][1] == center[i_z][1] + dl) {
							center[i][2] = 0;
							break;
						}
					}
				}*/