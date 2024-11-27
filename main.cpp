#include <GL/glut.h>
#include <cmath>
float kangarooX = 0.0f, kangarooY = -0.2f; // Initial position
bool isJumping = false;
float jumpHeight = 0.0f;
// Function to draw a circle or ellipse
void drawEllipse(float x, float y, float radiusX, float radiusY) {
    int numSegments = 100;
    glBegin(GL_POLYGON);
    for (int i = 0; i < numSegments; ++i) {
        float theta = 2.0f * 3.1415926f * float(i) / float(numSegments);
        float dx = radiusX * cosf(theta);
        float dy = radiusY * sinf(theta);
        glVertex2f(x + dx, y + dy);
    }
    glEnd();
}

// Function to draw a tree
void drawTree(float x, float y) {
    // Trunk
    glColor3f(0.545f, 0.271f, 0.075f); // Light brown
    glBegin(GL_POLYGON);
    glVertex2f(x - 0.02f, y);
    glVertex2f(x + 0.02f, y);
    glVertex2f(x + 0.02f, y + 0.2f);
    glVertex2f(x - 0.02f, y + 0.2f);
    glEnd();

    // Foliage
    glColor3f(0.0f, 0.5f, 0.0f); // Dark green
    drawEllipse(x, y + 0.25f, 0.1f, 0.15f);
    drawEllipse(x - 0.07f, y + 0.2f, 0.08f, 0.12f);
    drawEllipse(x + 0.07f, y + 0.2f, 0.08f, 0.12f);
}

// Function to draw a bird
void drawBird(float x, float y) {
    // Body
    glColor3f(0.0f, 0.0f, 0.0f); // Black
    drawEllipse(x, y, 0.05f, 0.025f);

    // Head
    drawEllipse(x + 0.06f, y + 0.01f, 0.015f, 0.015f);

    // Beak
    glColor3f(1.0f, 0.647f, 0.0f); // Orange
    glBegin(GL_TRIANGLES);
    glVertex2f(x + 0.07f, y + 0.015f);
    glVertex2f(x + 0.09f, y + 0.01f);
    glVertex2f(x + 0.07f, y + 0.005f);
    glEnd();

    // Wings
    glColor3f(0.1f, 0.1f, 0.1f); // Dark gray for wings
    glBegin(GL_TRIANGLES);
    glVertex2f(x - 0.02f, y);
    glVertex2f(x - 0.06f, y + 0.03f);
    glVertex2f(x, y + 0.01f);
    glEnd();

    // Tail
    glBegin(GL_TRIANGLES);
    glVertex2f(x - 0.05f, y - 0.01f);
    glVertex2f(x - 0.08f, y - 0.02f);
    glVertex2f(x - 0.04f, y - 0.02f);
    glEnd();

    // Eye
    glColor3f(1.0f, 1.0f, 1.0f); // White
    drawEllipse(x + 0.065f, y + 0.02f, 0.004f, 0.004f);

    glColor3f(0.0f, 0.0f, 0.0f); // Black pupil
    drawEllipse(x + 0.065f, y + 0.02f, 0.002f, 0.002f);
}


// Function to draw a crocodile
void drawCrocodile(float x, float y) {
    // Body
    glColor3f(0.0f, 0.5f, 0.0f); // Dark green
    drawEllipse(x, y, 0.1f, 0.03f);

    // Head
    drawEllipse(x + 0.12f, y, 0.03f, 0.02f);

    // Tail
    glBegin(GL_TRIANGLES);
    glVertex2f(x - 0.1f, y);
    glVertex2f(x - 0.15f, y + 0.02f);
    glVertex2f(x - 0.15f, y - 0.02f);
    glEnd();

    // Hands
    glColor3f(0.0f, 0.4f, 0.0f); // Slightly darker green
    glBegin(GL_TRIANGLES);
    glVertex2f(x - 0.04f, y + 0.025f);
    glVertex2f(x - 0.06f, y + 0.05f);
    glVertex2f(x - 0.02f, y + 0.03f);
    glEnd();

    glBegin(GL_TRIANGLES);
    glVertex2f(x - 0.04f, y - 0.025f);
    glVertex2f(x - 0.06f, y - 0.05f);
    glVertex2f(x - 0.02f, y - 0.03f);
    glEnd();

    // Eyes
    glColor3f(1.0f, 1.0f, 1.0f); // White
    drawEllipse(x + 0.13f, y + 0.01f, 0.007f, 0.007f);
    drawEllipse(x + 0.13f, y - 0.01f, 0.007f, 0.007f);

    glColor3f(0.0f, 0.0f, 0.0f); // Black pupils
    drawEllipse(x + 0.13f, y + 0.01f, 0.003f, 0.003f);
    drawEllipse(x + 0.13f, y - 0.01f, 0.003f, 0.003f);
}
// Function to draw the river
void drawRiver() {
    glColor3f(0.0f, 0.749f, 1.0f); // Light blue
    glBegin(GL_POLYGON);
    glVertex2f(-1.0f, -0.5f);
    glVertex2f(1.0f, -0.5f);
    glVertex2f(1.0f, -0.3f);
    glVertex2f(-1.0f, -0.3f);
    glEnd();
}

// Function to draw the sun
void drawSun() {
    glColor3f(1.0f, 1.0f, 0.0f); // Yellow
    drawEllipse(0.8f, 0.8f, 0.1f, 0.1f);
}
void drawKangourou(float x, float y) {
    // Scale factor for making the kangaroo larger
    float scale = 1.2f;

    // Slightly darker base color for the kangaroo
    float bodyR = 0.65f, bodyG = 0.55f, bodyB = 0.4f;
    float bellyR = 0.9f, bellyG = 0.8f, bellyB = 0.7f;

    // Patte gauche
    glColor3f(bodyR, bodyG, bodyB);
    glPushMatrix();
    glTranslatef(x + 0.084f * scale, y - 0.258f * scale, 0.0f);
    glRotatef(20.0f, 0.0f, 0.0f, -0.1f);
    drawEllipse(0.0f, 0.0f, 0.06f * scale, 0.018f * scale);
    glPopMatrix();

    // Patte droite
    glPushMatrix();
    glTranslatef(x - 0.084f * scale, y - 0.258f * scale, 0.0f);
    glRotatef(20.0f, 0.0f, 0.0f, 0.1f);
    drawEllipse(0.0f, 0.0f, 0.06f * scale, 0.018f * scale);
    glPopMatrix();

    // Main gauche
    glPushMatrix();
    glTranslatef(x + 0.08f * scale, y + 0.07f * scale, 0.0f);
    glRotatef(-40.0f, 0.0f, 0.0f, 0.1f);
    drawEllipse(0.0f, 0.0f, 0.09f * scale, 0.018f * scale);
    glPopMatrix();

    // Main droite
    glPushMatrix();
    glTranslatef(x - 0.08f * scale, y + 0.07f * scale, 0.0f);
    glRotatef(40.0f, 0.0f, 0.0f, 0.1f);
    drawEllipse(0.0f, 0.0f, 0.09f * scale, 0.018f * scale);
    glPopMatrix();

    // Queue
    glColor3f(bodyR, bodyG, bodyB);
    glPushMatrix();
    glTranslatef(x + 0.10f * scale, y - 0.13f * scale, 0.0f);
    glRotatef(-45.0f, 0.0f, 0.0f, 0.1f);
    drawEllipse(0.0f, 0.0f, 0.08f * scale, 0.03f * scale);
    glPopMatrix();

    // Oreille gauche
    glColor3f(bodyR, bodyG, bodyB);
    glPushMatrix();
    glTranslatef(x + 0.048f * scale, y + 0.252f * scale, 0.0f);
    glRotatef(-70.0f, 0.0f, 0.0f, -0.1f);
    drawEllipse(0.0f, 0.0f, 0.06f * scale, 0.018f * scale);
    glColor3f(bellyR, bellyG, bellyB);
    drawEllipse(0.0f, 0.0f, 0.042f * scale, 0.012f * scale);
    glPopMatrix();

    // Oreille droite
    glColor3f(bodyR, bodyG, bodyB);
    glPushMatrix();
    glTranslatef(x - 0.048f * scale, y + 0.252f * scale, 0.0f);
    glRotatef(-70.0f, 0.0f, 0.0f, 0.1f);
    drawEllipse(0.0f, 0.0f, 0.06f * scale, 0.018f * scale);
    glColor3f(bellyR, bellyG, bellyB);
    drawEllipse(0.0f, 0.0f, 0.042f * scale, 0.012f * scale);
    glPopMatrix();

    // Tête
    glColor3f(bodyR, bodyG, bodyB);
    glPushMatrix();
    glTranslatef(x, y + 0.18f * scale, 0.0f);
    drawEllipse(0.0f, 0.0f, 0.042f * scale, 0.06f * scale);
    glPopMatrix();

    // Corps
    glColor3f(bodyR, bodyG, bodyB);
    glPushMatrix();
    glTranslatef(x, y, 0.0f);
    drawEllipse(0.0f, 0.0f, 0.07f * scale, 0.15f * scale);
    glPopMatrix();

    // Ventre
    glPushMatrix();
    glColor3f(bellyR, bellyG, bellyB);
    drawEllipse(x, y - 0.05f * scale, 0.04f * scale, 0.08f * scale);
    glPopMatrix();

    // Jambes
    glColor3f(bodyR, bodyG, bodyB);
    glPushMatrix();
    glTranslatef(x - 0.044f * scale, y - 0.168f * scale, 0.0f);
    drawEllipse(0.0f, 0.0f, 0.022f * scale, 0.09f * scale);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(x + 0.044f * scale, y - 0.168f * scale, 0.0f);
    drawEllipse(0.0f, 0.0f, 0.022f * scale, 0.09f * scale);
    glPopMatrix();

    // Nez et yeux
    glColor3f(0.0f, 0.0f, 0.0f);
    glPushMatrix();
    glTranslatef(x, y + 0.174f * scale, 0.0f);
    drawEllipse(0.0f, 0.0f, 0.006f * scale, 0.006f * scale);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(x + 0.012f * scale, y + 0.204f * scale, 0.0f);
    drawEllipse(0.0f, 0.0f, 0.0042f * scale, 0.0042f * scale);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(x - 0.012f * scale, y + 0.204f * scale, 0.0f);
    drawEllipse(0.0f, 0.0f, 0.0042f * scale, 0.0042f * scale);
    glPopMatrix();
}



// Function to draw the landscape
void drawLandscape() {
    // Sky
    glColor3f(0.529f, 0.808f, 0.922f); // Light blue
    glBegin(GL_POLYGON);
    glVertex2f(-1.0f, 0.0f);
    glVertex2f(1.0f, 0.0f);
    glVertex2f(1.0f, 1.0f);
    glVertex2f(-1.0f, 1.0f);
    glEnd();

    // Ground
    glColor3f(0.196f, 0.804f, 0.196f); // Light green
    glBegin(GL_POLYGON);
    glVertex2f(-1.0f, -1.0f);
    glVertex2f(1.0f, -1.0f);
    glVertex2f(1.0f, 0.0f);
    glVertex2f(-1.0f, 0.0f);
    glEnd();
}

// Render function
void Display() {
    glClear(GL_COLOR_BUFFER_BIT);

    // Draw landscape
    drawLandscape();

    // Draw river
    drawRiver();

    // Draw trees
    drawTree(-0.6f, -0.1f);
    drawTree(0.0f, -0.1f);
    drawTree(0.6f, -0.1f);

    // Add bird to the tree on the right
    drawBird(0.6f, 0.5f);

    drawCrocodile(0.2f, -0.4f);
    // Draw crocodile near the river
    drawBird(-0.6f, 0.5f);

    // Draw the kangaroo
    glPushMatrix();
    glTranslatef(-0.250f, -0.24f, 1); // Adjust position
    drawKangourou(kangarooX, kangarooY + jumpHeight);
    glPopMatrix();


    // Draw sun
    drawSun();

    glFlush();
}
void handleKeypress(unsigned char key, int x, int y) {
    if (key == ' ') { // Spacebar for jumping
        if (!isJumping) isJumping = true;
    }
}

void handleSpecialKey(int key, int x, int y) {
    if (key == GLUT_KEY_LEFT) {
        kangarooX -= 0.05f; // Move left
    } else if (key == GLUT_KEY_RIGHT) {
        kangarooX += 0.05f; // Move right
    }
}
void update(int value) {
    if (isJumping) {
        jumpHeight += 0.02f;
        if (jumpHeight >= 0.2f) {
            isJumping = false;
        }
    } else if (jumpHeight > 0.0f) {
        jumpHeight -= 0.02f;
    }

    glutPostRedisplay();
    glutTimerFunc(16, update, 0); // Call update every 16ms
}
// Main function
int main(int argc, char *argv[]) {

    glutInit(&argc, argv);
    glutInitWindowSize(1000, 700);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Kangaroo, Crocodile, and Landscape");
    glutDisplayFunc(Display);
    glutKeyboardFunc(handleKeypress);
    glutSpecialFunc(handleSpecialKey);
    glutTimerFunc(16, update, 0);
    glClearColor(1.0f, 1.0f, 1.0f, 0.0f); // White background
    glutMainLoop();
    return 0;
}
