#include "ingredienttablemodel.h"

ingredientTableModel::ingredientTableModel(QObject *parent)
    : QAbstractTableModel(parent)
{
}
ingredientTableModel::ingredientTableModel(const QVector<Ingredient> &ingredients, QObject *parent)
    : QAbstractTableModel(parent)
    , ingredients(ingredients)
{
}

QVariant ingredientTableModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    // FIXME: Implement me!
    // FIXME: Implement me!
    if (role != Qt::DisplayRole)
        return QVariant();

    if (orientation == Qt::Horizontal) {
        switch (section) {
            case 0:
                return tr("Name");
            case 1:
                return tr("Quantity");
            case 2:
                return tr("Unit");
            default:
                break;
        }
    }
    if(orientation == Qt::Vertical)
    {
        return QString::number(section+1);
    }
    return QVariant();
}

bool ingredientTableModel::setHeaderData(int section, Qt::Orientation orientation, const QVariant &value, int role)
{
    if (value != headerData(section, orientation, role)) {
        // FIXME: Implement me!
        emit headerDataChanged(orientation, section, section);
        return true;
    }
    return false;
}


int ingredientTableModel::rowCount(const QModelIndex &parent) const
{
    return parent.isValid() ? 0 : ingredients.size();;
    // FIXME: Implement me!
}

int ingredientTableModel::columnCount(const QModelIndex &parent) const
{
    return parent.isValid() ? 0 : 3;

    // FIXME: Implement me!
}

QVariant ingredientTableModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();
    if (index.row() >= ingredients.size() || index.row() < 0)
        return QVariant();
    if (role == Qt::DisplayRole){
        const auto &ingredient = ingredients.at(index.row());

        switch (index.column()) {
            case 0:
                return ingredient.getIngredientName();
            case 1:
                //return ingredient.getIngredientQuantity();
                return ingredient.getIngredientQuantity();
                                //return QVariant::fromValue(recipes);

            case 2:
                return ingredient.getIngredientUnit();
            default:
                break;

        }
    }
    return QVariant();
}

bool ingredientTableModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (index.isValid() && role == Qt::EditRole) {
        const int row = index.row();
        auto ingredient = ingredients.at(row);

        switch (index.column()) {
            case 0:
                ingredient.setIngredientName(value.toString());
                break;
            case 1:
                ingredient.setIngredientQuantity(value.toFloat());
                break;
            case 2:
                ingredient.setIngredientUnit(value.toString());
                break;
            default:
                return false;
        }
        ingredients.replace(row, ingredient);
        emit dataChanged(index, index, {Qt::DisplayRole, Qt::EditRole});

        return true;
    }

    return false;
}

Qt::ItemFlags ingredientTableModel::flags(const QModelIndex &index) const
{
    if (!index.isValid())
        return Qt::ItemIsEnabled;

    return QAbstractTableModel::flags(index) | Qt::ItemIsEditable;
}
const QVector<Ingredient> &ingredientTableModel::getIngredient() const
{
    return ingredients;
}

bool ingredientTableModel::insertRows(int position, int rows, const QModelIndex &index)
{
    Q_UNUSED(index);
    beginInsertRows(QModelIndex(), position, position + rows - 1);
    // FIXME: Implement me!
    for (int row = 0; row < rows; ++row)
        ingredients.insert(position, {QString(), float(), QString()});
    endInsertRows();
    return true;
}

//bool ingredientTableModel::insertColumns(int column, int count, const QModelIndex &parent)
//{
//    beginInsertColumns(parent, column, column + count - 1);
//    // FIXME: Implement me!
//    endInsertColumns();
//}

bool ingredientTableModel::removeRows(int position, int rows, const QModelIndex &parent)
{
    Q_UNUSED(parent);
    beginRemoveRows(QModelIndex(), position, position + rows - 1);
    for (int row = 0; row < rows; ++row)
        ingredients.removeAt(position);
    // FIXME: Implement me!
    endRemoveRows();
    return true;
}

//bool ingredientTableModel::removeColumns(int column, int count, const QModelIndex &parent)
//{
//    beginRemoveColumns(parent, column, column + count - 1);
//    // FIXME: Implement me!
//    endRemoveColumns();
//}
