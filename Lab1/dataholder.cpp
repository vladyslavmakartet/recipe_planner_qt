#include "dataholder.h"

Recipe::Recipe(){}
Recipe::Recipe(const QString Name, const QString Description, QVector<Ingredient> Ingredients)
{
    recipeName = Name;
    recipeDescription = Description;
    ingredients = Ingredients;
}
QString Recipe::getRecipeName() const
{
    return this->recipeName;
}
QString Recipe::getRecipeDescription() const
{
    return this->recipeDescription;
}
void Recipe::setRecipeName(const QString Name)
{
    this->recipeName = Name;
}
void Recipe::setRecipeDescription(const QString Description)
{
    this->recipeDescription = Description;
}
QVector<Ingredient> Recipe::getRecipeIngredients() const
{
    return this->ingredients;
}
//void Recipe::setRecipeIngredient(const Ingredient data)
//{
//    this->ingredients.append(data);
//}


void Recipe::setRecipeIngredients(const QVector<Ingredient> data)
{
    this->ingredients=data;
}


Ingredient::Ingredient(){}
Ingredient::Ingredient(const QString newName, const float newQuantity, const QString newUnit)
{
    name = newName;
    quantity = newQuantity;
    unit = newUnit;
}
QString Ingredient::getIngredientName() const
{
    return this->name;
}
float Ingredient::getIngredientQuantity() const
{
    return this->quantity;
}
//float Ingredient::getIngredientQuantity() const
//{
//    return this->quantity;
//}
QString Ingredient::getIngredientUnit() const
{
    return this->unit;
}
void Ingredient::setIngredientName(const QString newName)
{
    this->name = newName;
}
void Ingredient::setIngredientQuantity(const float newQuantity)
{
    this->quantity = newQuantity;
}
//void Ingredient::setIngredientQuantity(const float newQuantity)
//{
//    this->quantity = newQuantity;
//}
void Ingredient::setIngredientUnit(const QString newUnit)
{
    this->unit = newUnit;
}
bool Ingredient::checkIfEqual(QString name, float quantity, QString unit)
{
    if (this->name == name || this->quantity == quantity || this->unit == unit)
        return true;
    return false;
}
bool Ingredient::operator==(const Ingredient &rhs) const
{
    if(this->name == rhs.name && this->quantity == rhs.quantity && this->unit == rhs.unit)
        return true;
    return false;
}
//bool operator==(const Ingredient &lhs, const Ingredient &rhs)
//{
//    if (lhs.getIngredientName() == rhs.getIngredientName()
//            || lhs.getIngredientQuantity() == rhs.getIngredientQuantity()
//            || lhs.getIngredientUnit() == rhs.getIngredientUnit())
//        return true;
//    return false;
//}
