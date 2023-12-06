#ifndef MAPDESIGNER_H
#define MAPDESIGNER_H

#include <QMainWindow>
#include <QMouseEvent>
#include <QContextMenuEvent>
#include <QLinkedList>
#include "mapelement.h"

namespace Ui {
class MapDesigner;
}

class MapDesigner : public QMainWindow
{
    Q_OBJECT
public slots:
    void paintEvent(QPaintEvent * event);
private slots:
    void newFile();
    void open();
    bool save();
    bool saveAs();
    void addWall();
    void addObject();
    void addDoor();
    void editElement();
public:
    explicit MapDesigner(QWidget *parent = 0);
    ~MapDesigner();
    void contextMenuEvent(QContextMenuEvent *event);
protected:
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
private:
    void createActions();
    void createMenus();

    QAction *newAction;
    QAction *openAction;
    QAction *saveAction;
    QAction *saveAsAction;
    QMenu *fileMenu;

    QAction *addWallAction;
    QAction *addObjectAction;
    QAction *addDoorAction;
    QAction *addEditAction;

    bool isTracking;
    enum class Operation { NONE, WALL, DOOR, OBJECT, EDIT , DELETE} currentOperation;

    Ui::MapDesigner *ui;

    Qt::MouseButton DrawingButton;
    QLinkedList<MapElement *> *mapElements;
    MapElement *currentElement;
};

#endif // MAPDESIGNER_H
