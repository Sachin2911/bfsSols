import math

def calculate_gravitational_force(M, A, B, C, m, xP, yP, Nx, Nr, Ntheta):
    # volume of the asteroid
    V = (4/3) * A * B * C * math.pi
    # density of asteroid
    D = M / V

    # length of the intervals for x
    dx = 2 * A / Nx
    # length of the intervals for theta
    dtheta = 2 * math.pi / Ntheta

    # set the components of the resultant gravitational force to zero
    sumFGx = 0
    sumFGy = 0
    sumFGz = 0

    for u in range(0, Nx):
        # calculate midpoints for x
        x_u = (2 * A - 2 * u * dx - dx) / 2

        # calculate the half-width of the asteroid and the length of the intervals for ru
        ru = B * math.sqrt(1 - (x_u / A) ** 2)
        dru = ru / Nr

        for v in range(0, Nr):
            # calculate midpoints along the half-width
            ru_v = (2 * v + 1) * dru / 2

            for w in range(0, Ntheta):
                # calculate midpoints of the segments
                theta_w = (2 * w + 1) * dtheta / 2

                # determine the position of a portion of the asteroid
                x_uvw = x_u
                y_uvw = ru_v * math.cos(theta_w)
                z_uvw = ru_v * math.sin(theta_w)

                # determine the mass of each portion of the planet
                M_uvw = D * ru_v * dx * dru * dtheta

                # determine the cube of the distance between the portion of the asteroid and the particle
                d = math.sqrt((xP - x_uvw) ** 2 + (yP - y_uvw) ** 2 + z_uvw ** 2) ** 3

                # determine the components of the gravitational force acting on the particle
                FGx = -m * M_uvw * (xP - x_uvw) / d
                FGy = -m * M_uvw * (yP - y_uvw) / d
                FGz = m * M_uvw * z_uvw / d

                # determine the components of resultant gravitational force acting on the particle
                sumFGx += FGx
                sumFGy += FGy
                sumFGz += FGz

    return sumFGx, sumFGy

# Given parameters
M = 569
m = 1
A = 15
B = 4
C = 4
Nx = 20
Nr = 10
Ntheta = 8

points = [(13, 7, 0), (11, 11, 0), (8, 13, 0)]
for xP, yP, _ in points:
    sumFGx, sumFGy = calculate_gravitational_force(M, A, B, C, m, xP, yP, Nx, Nr, Ntheta)
    print(f"Point ({xP}, {yP}, 0): sumFGx = {round(sumFGx, 3)}, sumFGy = {round(sumFGy, 3)}")
