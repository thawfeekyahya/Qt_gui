# QT's Model / View Architecture

Models are used to store data. Qt provides several widgets for viewing the data items held in models.

### Views
All the standard views are provided wtih a default ** QStyledItemDelegate ** class. This class represents items in a view.

### Models
Probalby the most import fact to understand about Qt's Model is that although there is a single uniform API, there are 2 completely different kinds of models.

1. Table Model // Works in terms of row & column
2. Tree Model // Works in terms of parent & children.


**QStandardItemModel** is a generic model, which can be used as list, table or tree model.

**QAbstractItemModel** this provdies the base class for custom models

``` mermaid
---	
title: Model Inheritance;
---
classDiagram

QStringListModel--|>QAbstractListModel
QAbstractListModel-->QAbstractItemModel

QSortFilterPorxyModel-->QAbstractProxyModel
QAbstractProxyModel-->QAbstractItemModel


```




