#ifndef DATAHOLDER_H
#define DATAHOLDER_H
#include <qstring.h>
#include <QFloat16>
#include <QList>
class Recipe;
class Ingredient;

class Recipe
{
    QString recipeName;
    QString recipeDescription;
    QVector<Ingredient> ingredients;
public:
    Recipe();
    Recipe(const QString Name, const QString Description, const QVector<Ingredient> Ingredients);
    QString getRecipeName() const;
    QString getRecipeDescription() const;
    QVector<Ingredient> getRecipeIngredients() const;
    void setRecipeName(const QString);
    void setRecipeDescription(const QString);
    //void setRecipeIngredient(const Ingredient data);
    void setRecipeIngredients(const QVector<Ingredient> data);
};
Q_DECLARE_METATYPE(Recipe)

class Ingredient
{
    QString name;
    //qfloat16 quantity;
    float quantity;
    QString unit;
public:
    Ingredient();
    Ingredient(const QString name, const float quantity, const QString unit);
    QString getIngredientName() const;
    //qfloat16 getIngredientQuantity() const;
    float getIngredientQuantity() const;
    QString getIngredientUnit() const;
    void setIngredientName(const QString);
    //void setIngredientQuantity(const qfloat16);
    void setIngredientQuantity(const float);
    void setIngredientUnit(const QString);
    bool checkIfEqual(QString name, float quantity, QString unit);
    bool operator==(const Ingredient &rhs)const;
    //bool operator==(const Ingredient &lhs, const Ingredient &rhs);
};
Q_DECLARE_METATYPE(Ingredient)

#endif // DATAHOLDER_H
