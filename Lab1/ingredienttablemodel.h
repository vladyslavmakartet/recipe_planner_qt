#ifndef INGREDIENTTABLEMODEL_H
#define INGREDIENTTABLEMODEL_H

#include <QAbstractTableModel>
#include "dataholder.h"

class ingredientTableModel : public QAbstractTableModel
{
    Q_OBJECT

public:
    explicit ingredientTableModel(QObject *parent = nullptr);
    explicit ingredientTableModel(const QVector<Ingredient> &ingredients, QObject *parent = nullptr);

    // Header:
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;

    bool setHeaderData(int section, Qt::Orientation orientation, const QVariant &value, int role = Qt::EditRole) override;

    // Basic functionality:
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    // Editable:
    bool setData(const QModelIndex &index, const QVariant &value,
                 int role = Qt::EditRole) override;

    Qt::ItemFlags flags(const QModelIndex& index) const override;

    // Add data:
    bool insertRows(int row, int count, const QModelIndex &parent = QModelIndex()) override;
    //bool insertColumns(int column, int count, const QModelIndex &parent = QModelIndex()) override;

    // Remove data:
    bool removeRows(int row, int count, const QModelIndex &parent = QModelIndex()) override;
    //bool removeColumns(int column, int count, const QModelIndex &parent = QModelIndex()) override;
    const QVector<Ingredient> &getIngredient() const;

private:
    QVector<Ingredient> ingredients;
};

#endif // INGREDIENTTABLEMODEL_H
