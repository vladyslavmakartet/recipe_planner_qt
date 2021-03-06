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
bool Recipe::operator==(const Recipe &rhs) const
{
    if(this->recipeName == rhs.recipeName
            && this->recipeDescription == rhs.recipeDescription
            && this->ingredients == rhs.ingredients)
        return true;
    return false;
}

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
    if(this->name == rhs.name &&  this->unit == rhs.unit)
        return true;
    return false;
}
void Recipe::write(QJsonObject &json) const
{

    QJsonArray ingredientArray;
    json["name"] = recipeName;
    json["recipe"] = recipeDescription;
    for (const Ingredient &ingredient : ingredients) {
        QJsonObject ingredientObject;
        ingredient.write(ingredientObject);
        ingredientArray.append(ingredientObject);
    }
    json["ingredients"] = ingredientArray;

}
void Ingredient::write(QJsonObject &json) const
{
    json["name"] = name;
    json["quantity"] = QString::number(quantity);
    json["unit"] = unit;

}
void Recipe::read(const QJsonObject &json)
{
    if (json.contains("name") && json["name"].isString())
        recipeName = json["name"].toString();
    if (json.contains("recipe") && json["recipe"].isString())
        recipeDescription = json["recipe"].toString();
    if (json.contains("ingredients") && json["ingredients"].isArray()){
        QJsonArray ingredientsArray = json["ingredients"].toArray();
        ingredients.clear();
        ingredients.reserve(ingredientsArray.size());
        for (int ingredientIndex = 0; ingredientIndex < ingredientsArray.size(); ++ingredientIndex){
            QJsonObject ingredientsObject = ingredientsArray[ingredientIndex].toObject();
            Ingredient ingredient;
            ingredient.read(ingredientsObject);
            ingredients.append(ingredient);
        }

    }
}
void Ingredient::read(const QJsonObject &json)
{
    if (json.contains("name") && json["name"].isString())
        name = json["name"].toString();

    if (json.contains("quantity") && json["quantity"].isString())
        quantity = json["quantity"].toString().toFloat();

    if (json.contains("unit") && json["unit"].isString())
        unit = json["unit"].toString();

}
