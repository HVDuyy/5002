class CRectangle {
private:
    double width;
    double height;

public:
    // Constructors
    CRectangle() : width(0), height(0) {}
    CRectangle(double w, double h) : width(w), height(h) {}

    // Setters
    void setWidth(double w) {
        width = w;
    }

    void setHeight(double h) {
        height = h;
    }

    // Getters
    double getWidth() const {
        return width;
    }

    double getHeight() const {
        return height;
    }

    // Calculate area
    double area() const {
        return width * height;
    }
};
