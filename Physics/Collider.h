#pragma once
#include "math.h"
#include <QPixmap>
#include <QGraphicsPixmapItem>
#include "qmath.h"

/*The collider class which takes care of the collision of two or more rigid bodies*/

class Collider : public QObject{
    Q_OBJECT
    private:
        int id; //Collider ID
        double skin_depth_percent = 0; //percentage of the body that is allowed to overlap with another collider
        int skin_depth_pixels = 0; //same thing as the skin_depth_percent but it is in pixels
        int countblack = 0; //counts the number of black pixels in a collider
        QImage colliding_map = QImage(42,42,QImage::Format_RGB32); //default colliding map

    protected:
        double x = 0, y = 0; //default position of x and y
        double cmx, cmy; //Central of mass x and y coordinate

    public:
        virtual bool on_collision_do(Collider &other);
        virtual void circ_delete(int x, int y, double radius);
        bool is_ground = false;

        bool grounded = false;

        virtual bool isWormAlive();
        virtual void addAmmo(int weaponID, int amountAmmo);
        //Constructors

        Collider();
        Collider(double ix, double iy, QImage map);
        Collider(double ix, double iy); //map is the default black square 32x32 pixels
        virtual ~Collider();
        //get and set private variables

        int getId() const; // can be used
        void setId(int iid); // should not be used by other classes apart from the physics engine

        void setSkin(double depth_percent); //sets the skin_depth_percent and recomputes the skin_depth_pixels and countblack

        double getX() const;
        double getY() const;

        void setX(double x1);
        void setY(double y1);

        double getcmX() const;
        double getcmY() const;

        void setcmX(double cx);
        void setcmY(double cy);

        QImage get_map() const;
        void set_map(QImage map);

        int getWidth() const;
        int getHeight() const;

        void change_pixel(int i, int j, QColor color); //changes the pixel color of the map
        QRgb get_color(int i, int j) const;

        //check_collision method returns (bool is_colliding, Normal_Force); Normal_Force = (norm_x, norm_y)

        QPair<bool, QPair<double, double>> check_collision(Collider &other);

};
