# Qt Meta Object System

Apart from providing signal / slot communication mechanism , Qt's Meta Object system provides other useful functionalites such as

- QtObject subclass runtime information
- Lays the foundation for QtScript Module
- Text translations

## Useful functions from MOC

```
QObject::metaObject() //Provides info on class name / super class name ,signal / slot information
QObject::tr()
QObject::qt_metacall()
QObject::inhertis()

QTimer *timer = new QTimer;         // QTimer inherits QObject
timer->inherits("QTimer");          // returns true
timer->inherits("QObject");         // returns true
timer->inherits("QAbstractButton"); // returns false

```
