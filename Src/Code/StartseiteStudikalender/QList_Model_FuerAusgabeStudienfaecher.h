#ifndef QLIST_MODEL_FUERAUSGABESTUDIENFAECHER_H
#define QLIST_MODEL_FUERAUSGABESTUDIENFAECHER_H


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


class TTestModel : public QAbstractTableModel
{
    Q_OBJECT

public:
    TTestModel(QObject *parent = 0);

    void populateData(const QList<int> &idStudienfach,const  QList<QString> &Bezeichnung, const QList<int> &ECTS,const QList<int> &SWS,const QList<int> &Eigenstunden);

    int rowCount(const QModelIndex &parent = QModelIndex()) const Q_DECL_OVERRIDE;
    int columnCount(const QModelIndex &parent = QModelIndex()) const Q_DECL_OVERRIDE;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const Q_DECL_OVERRIDE;
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const Q_DECL_OVERRIDE;

private:
    QList<int> LidStudienfach;
    QList<QString> LBezeichnung;
    QList<int> LECTS;
    QList<int> LSWS;
    QList<int> LEigenstunden;

};



inline TTestModel::TTestModel(QObject *parent) : QAbstractTableModel(parent)
{
}

// Create a method to populate the model with data:
inline void TTestModel::populateData(const QList<int> &idStudienfach,const  QList<QString> &Bezeichnung,const QList<int> &ECTS,const QList<int> &SWS,const QList<int> &Eigenstunden)
{
    LidStudienfach.clear();
    LidStudienfach = idStudienfach;
    LBezeichnung.clear();
    LBezeichnung=Bezeichnung;
    LECTS.clear();
    LECTS = ECTS;
    LSWS.clear();
    LSWS = SWS;
    LEigenstunden.clear();
    LEigenstunden = Eigenstunden;
    return;
}

inline int TTestModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return LidStudienfach.length();
}

inline int TTestModel::columnCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return 5;
}

inline QVariant TTestModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid() || role != Qt::DisplayRole) {
        return QVariant();
    }
    if (index.column() == 0) {
        return LidStudienfach[index.row()];
    } else if (index.column() == 1) {
        return LBezeichnung[index.row()];
    }else if (index.column() == 2) {
        return LECTS[index.row()];
    }else if (index.column() == 3) {
        return LSWS[index.row()];
    }else if (index.column() == 4) {
        return LEigenstunden[index.row()];
    }
    return QVariant();
}

inline QVariant TTestModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role == Qt::DisplayRole && orientation == Qt::Horizontal) {
        if (section == 0) {
            return QString("idStudienfach");
        } else if (section == 1) {
            return QString("Studienfach");
        }
        else if (section == 2) {
                    return QString("ECTS");
                }
        else if (section == 3) {
                    return QString("SWS");
                }
        else if (section == 4) {
                    return QString("Eigenstunden");
                }
    }
    return QVariant();
}



#endif // QLIST_MODEL_FUERAUSGABESTUDIENFAECHER_H
