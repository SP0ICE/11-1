#include <QApplication>
#include <QWidget>
#include <QLineEdit>
#include <QLabel>
#include <QPushButton>
#include <QFileDialog>

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    QWidget window;
    window.setWindowTitle("Image Viewer");
    window.setFixedSize(640, 480);

    QLineEdit *lineEdit = new QLineEdit(&window);
    lineEdit->setGeometry(10, 10, 500, 30);

    QLabel *label = new QLabel(&window);
    label->setGeometry(10, 50, 620, 420);
    label->setAlignment(Qt::AlignCenter);

    QPushButton *button = new QPushButton("Open", &window);
    button->setGeometry(520, 10, 100, 30);
    QObject::connect(button, &QPushButton::clicked, [&](){
        QString fileName = QFileDialog::getOpenFileName(&window, "Open Image", "", "Image Files (*.png *.jpg *.bmp)");
        if (!fileName.isEmpty()) {
            QPixmap pixmap(fileName);
            label->setPixmap(pixmap.scaled(label->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
            lineEdit->setText(fileName);
        }
    });

    window.show();

    return app.exec();
}