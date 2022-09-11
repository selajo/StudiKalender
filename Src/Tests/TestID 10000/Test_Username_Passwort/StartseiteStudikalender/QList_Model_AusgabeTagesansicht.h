#ifndef QLIST_MODEL_AUSGABETAGESANSICHT_H
#define QLIST_MODEL_AUSGABETAGESANSICHT_H

#include <QMainWindow>
#include <QtSql>
#include <QSqlDatabase>

/*
 *
 * Author André Zimmer
 *
 */


//Klasse für die Ausgabe der Tagesansicht
//Vorlage
//https://riptutorial.com/de/qt/example/13705/eine-einfache-schreibgeschutzte-tabelle-zum-anzeigen-von-daten-aus-einem-modell
//aber abgeändert für unser eigenes Projekt


class TestModel : public QAbstractTableModel
{
    Q_OBJECT

public:
    TestModel(QObject *parent = 0);

    void populateData(const QList<int> &idTermin,const  QList<QString> &Terminname,const QList<QDate> &Datum,const QList<QTime> &Beginn,const QList<QTime> &Ende);

    int rowCount(const QModelIndex &parent = QModelIndex()) const Q_DECL_OVERRIDE;
    int columnCount(const QModelIndex &parent = QModelIndex()) const Q_DECL_OVERRIDE;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const Q_DECL_OVERRIDE;
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const Q_DECL_OVERRIDE;

private:
    QList<int> LidTermin;
    QList<QString> LTerminname;
    QList<QDate> LDatum;
    QList<QTime> LBeginn;
    QList<QTime> LEnde;

};



inline TestModel::TestModel(QObject *parent) : QAbstractTableModel(parent)
{
}

// Create a method to populate the model with data:
inline void TestModel::populateData(const QList<int> &idTermin,const  QList<QString> &Terminname,const QList<QDate> &Datum,const QList<QTime> &Beginn,const QList<QTime> &Ende)
{
    LidTermin.clear();
    LidTermin = idTermin;
    LTerminname.clear();
    LTerminname=Terminname;
    LDatum.clear();
    LDatum = Datum;
    LBeginn.clear();
    LBeginn = Beginn;
    LEnde.clear();
    LEnde = Ende;
    return;
}

inline int TestModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return LidTermin.length();
}

inline int TestModel::columnCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return 5;
}

inline QVariant TestModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid() || role != Qt::DisplayRole) {
        return QVariant();
    }
    if (index.column() == 0) {
        return LidTermin[index.row()];
    } else if (index.column() == 1) {
        return LTerminname[index.row()];
    }else if (index.column() == 2) {
        return LDatum[index.row()];
    }else if (index.column() == 3) {
        return LBeginn[index.row()];
    }else if (index.column() == 4) {
        return LEnde[index.row()];
    }
    return QVariant();
}

inline QVariant TestModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role == Qt::DisplayRole && orientation == Qt::Horizontal) {
        if (section == 0) {
            return QString("idTermin");
        } else if (section == 1) {
            return QString("Terminname");
        }
        else if (section == 2) {
                    return QString("Datum");
                }
        else if (section == 3) {
                    return QString("Beginn");
                }
        else if (section == 4) {
                    return QString("Ende");
                }
    }
    return QVariant();
}

#endif // QLIST_MODEL_AUSGABETAGESANSICHT_H
